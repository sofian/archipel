//#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <mozzi_fixmath.h>
#include <Sample.h>
#include <Streaming.h>

#include <IRremote.h>

#include <qualia/ga/BinaryChromosome.h>
#include <qualia/util/map.h>


#include "SoundPlayer.h"


/**
 * Settings.
 */
//#define SERIAL_IR          Serial1
//#define SERIAL_IR_BAUDRATE 9600
/// Infrared input.
#define IR_IN              19 // receiving on Serial1

/// Indicator LED output.
#define INDICATOR_LED_OUT 30

/// Mozzi control rate.
#define CONTROL_RATE 64

/// Mutation rate.
#define MUTATE_RATE 0.01f

///

/// List of genes.
enum {

  GENE_UNIT_1_ID,
  GENE_UNIT_1_PERIOD_SIGN,
  GENE_UNIT_1_PERIOD,
  GENE_UNIT_1_MIX_NEXT,

  GENE_HAS_UNIT_2,

  GENE_UNIT_2_ID,
  GENE_UNIT_2_PERIOD_SIGN,
  GENE_UNIT_2_PERIOD,
  GENE_UNIT_2_MIX_NEXT,

  GENE_HAS_UNIT_3,

  GENE_UNIT_3_ID,
  GENE_UNIT_3_PERIOD_SIGN,
  GENE_UNIT_3_PERIOD,
  GENE_UNIT_3_MIX_NEXT,

  N_GENES
};

/// Gene sizes.
const uint8_t GENE_SIZES[] = { 2, 1, 4, 4,
                               1,
                               2, 1, 4, 4,
                               1,
                               2, 1, 4, 4,
                              };
/**
 * Globals.
 */

/// The sound player..
SoundPlayer player;

/// IR remote receiver.
IRrecv irrecv(IR_IN);

/// Chromosome properties.
BinaryChromosomeProperties info(N_GENES, GENE_SIZES);

/// The device's DNA.
BinaryChromosome           dna(&info);

/// Placeholder for receiving the message DNA.
BinaryChromosome           messageDna(&info);

/// Placeholders to generate offsprings.
BinaryChromosome           offspring1(&info);
BinaryChromosome           offspring2(&info);

/// Bit distance between two chromosomes.
int distanceDNA(const BinaryChromosome& c1, const BinaryChromosome& c2) {
  int diff = 0;
  unsigned int bit = info.bitSize();
  while (bit--)
    diff += (arrayBitRead(c1.code, bit) != arrayBitRead(c2.code, bit) ? 1 : 0);
  return diff;
}

/// Adds a sound unit to player starting from start gene.
void addUnitFromDNA(int startGene) {
  int geneId         = startGene++;
  int genePeriodSign = startGene++;
  int genePeriod     = startGene++;
  int geneMixNext    = startGene++;

  uint8_t id = dna.getGeneValue(geneId);
  int sign = dna.getGeneValue(genePeriodSign) ? +1 : -1;
  float period = mapReal(dna.getGeneValue(genePeriod), 0, dna.maxGeneValue(genePeriod), 0.5f, 2.0f);
  period *= period;
  period *= sign;
  float mixNext = mapReal(dna.getGeneValue(geneMixNext), 0, dna.maxGeneValue(geneMixNext), 0.5f, 1.0f);

  player.addUnit(id, period, mixNext);
}

// Temporary struct to hold IR messages before transferring them to code.
struct __decode_results_code {
  uint32_t value;
  int8_t  decodeType : 4;
  uint16_t panasonicAddress : 12;
};

uint64_t hash(const decode_results& result) {
//#define __HASH_PRIME 31
#define __HASH_PRIME 331
  uint64_t hash = 0;
  uint64_t n    = (1ULL << info.bitSize()); // n different values in DNA string

  __decode_results_code rc;
  rc.value            = result.value;
  rc.decodeType       = result.decode_type == UNKNOWN ? 0 : result.decode_type;
  rc.panasonicAddress = result.panasonicAddress + result.value; // we mix both because we won't have panasonic address often

  uint8_t* ptr = (uint8_t*)&rc;
  for (int i = 0; i<sizeof(__decode_results_code); i++)
    hash = (__HASH_PRIME * hash + *ptr++) % n;

  return hash;
}

/// Transfers decoded IR message to DNA code.
void decodeResultsToDNA(uint8_t* code, const decode_results& result) {
  __decode_results_code rc;
  rc.value            = result.value;
  rc.decodeType       = result.decode_type == UNKNOWN ? 0 : result.decode_type;
  rc.panasonicAddress = result.panasonicAddress + result.value; // we mix both because we won't have panasonic address often

  if (info.byteSize() <= sizeof(rc)) {
    // Initialize code to zero.
    memset(code, 0, info.byteSize());

    uint8_t* ptr = (uint8_t*)&rc;
    for (int i = 0; i<sizeof(__decode_results_code); i++)
      code[i % info.byteSize()] += *ptr++;
  }
  else {
    uint8_t* ptr = (uint8_t*)&rc;
    for (int i = 0; i<info.byteSize(); i++)
      code[i] = ptr[i % sizeof(__decode_results_code)];
  }
}

/// Resets sound player based on current DNA.
void resetPlayerFromDNA(bool restart=true) {
  // Reset player.
  player.reset();

  // Add unit based on genes.
  addUnitFromDNA(GENE_UNIT_1_ID);
  if (dna.getGeneValue(GENE_HAS_UNIT_2)) {
    addUnitFromDNA(GENE_UNIT_2_ID);
    if (dna.getGeneValue(GENE_HAS_UNIT_3)) {
      addUnitFromDNA(GENE_UNIT_3_ID);
    }
  }

  // Restart player.
  if (restart)
    player.start();
}

/// Setup.
void setup() {
  // Init indicator LED.
  pinMode(INDICATOR_LED_OUT, OUTPUT);
  digitalWrite(INDICATOR_LED_OUT, HIGH);

  // Start serial.
  Serial.begin(9600);

//  SERIAL_IR.begin(SERIAL_IR_BAUDRATE);
  irrecv.enableIRIn();

  // Init chromosomes.
  dna.init();
  messageDna.init();

  // Start Mozzi output.
  startMozzi();

  // Set player from DNA and start it.
  resetPlayerFromDNA();

  delay(100);
  digitalWrite(INDICATOR_LED_OUT, LOW);
}

/// Utility function to read an integer as an ascii.
int serialReadInt() {
  int val = Serial.read() - '0';
  return constrain(val, 0, 9);
}

/// Mozzi update control.
void updateControl() {
  static decode_results results;

  if (irrecv.decode(&results)) {
    digitalWrite(INDICATOR_LED_OUT, HIGH);

    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    Serial.println(results.value, HEX);
    Serial << results.bits << " bits" << endl;

    if (results.value != REPEAT) {
//      uint64_t h = hash(results);
//      Serial << "Hash: " << (unsigned long)h << endl;

      int nBytes = min(results.bits/8, info.byteSize());

      // Generate a DNA string using serial information.
      decodeResultsToDNA(messageDna.code, results);
//      Q_ARRAY_COPY(messageDna.code, (uint8_t*)&results.value, uint8_t, info.byteSize());
//      Q_ARRAY_COPY(messageDna.code, (uint8_t*)&hash, uint8_t, info.byteSize());

      // Generate offsprings.
      BinaryChromosome::crossoverTwoPoint(dna, messageDna, &offspring1, &offspring2);

      // Choose one of the offsprings.
      int dist1 = distanceDNA(dna, offspring1);
      int dist2 = distanceDNA(dna, offspring2);
      if (dist1 == dist2)
        dna.copyFrom( random(2) ? offspring1 : offspring2 );
      else if (dist1 < dist2) {
        dna.copyFrom( offspring1 );
      }
      else
        dna.copyFrom( offspring2 );
  //    dna.copyFrom(messageDna);

      // Mutate
      dna.mutate(MUTATE_RATE);

      // Reset player params from new DNA and restart it.
      resetPlayerFromDNA();
    }

    // Get ready to receive the next IR-remote signal.
    irrecv.resume();

    digitalWrite(INDICATOR_LED_OUT, LOW);
  }

  if (Serial.peek() == 'M') {
    // mutate
    Serial.read();
    dna.mutate(MUTATE_RATE);

    resetPlayerFromDNA();
  }
//
//  if (Serial.available() >= info.nGenes()) {
//    Serial << "Change DNA" << endl;
//    for (int i=0; i<info.nGenes(); i++) {
//      int val = serialReadInt();
//      Serial << val << endl;
//      dna.setGeneValue(i, val);
//    }
//
//    resetPlayerFromDNA();
//  }
/*  if (readSoundParams()) {
    applyParams();
    oiseau.start();
  }*/
}

/// Mozzi update audio.
int updateAudio() {
  if (player.hasNext()) {
    return player.next();
  }
  else {
    return 0;
  }
}

/// Loop.
void loop() {
  audioHook();
}
