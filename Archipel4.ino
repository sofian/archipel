//#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <mozzi_fixmath.h>
#include <Sample.h>
#include <Streaming.h>

#include <IRremote.h>

#include <qualia/ga/BinaryChromosome.h>
#include <qualia/util/map.h>

#include "SuperTimer.h"

#include "SoundPlayer.h"

#include <Sleep_n0m1.h>

/**
 * Settings.
 */
//#define SERIAL_IR          Serial1
//#define SERIAL_IR_BAUDRATE 9600
/// Infrared input.
#define IR_IN              19 // receiving on Serial1

/// Indicator LED output.
#define INDICATOR_LED_OUT  30

/// Open analog pin for random init.
#define RANDOM_AIN         0

/// Mozzi control rate.
#define CONTROL_RATE 64

/// Mutation rate.
#define MUTATE_RATE 0.01f

/// Delay between detection of IR signal and sound playback.
// cancelled!
#define TRIGGER_DELAY_MIN      0
#define TRIGGER_DELAY_MAX      0
#define TRIGGER_DELAY_NOISE    0

/// Delay after which the bird will play a sound even if there was no trigger.
#define AUTO_PLAY_DELAY_MIN   30000UL
#define AUTO_PLAY_DELAY_MAX   60000UL
#define AUTO_PLAY_DELAY_NOISE 10000UL

/// Delay after which auto-play stops if there were no triggers.
//#define SILENT_MODE_DELAY   10000UL // test
#define SILENT_MODE_DELAY   240000UL // 4 min

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
/*  GENE_UNIT_3_MIX_NEXT,*/

  GENE_UNIT_1_REPEAT,
  GENE_UNIT_1_REPEAT_END_PERIOD,

  GENE_TRIGGER_DELAY,
  GENE_AUTO_PLAY_DELAY,

  N_GENES
};

/// Gene sizes.
const uint8_t GENE_SIZES[] = { 3, 1, 6, 4, // unit 1
                               1,          // has unit 2?
                               3, 1, 6, 4, // unit 2
                               1,          // has unit 3?
                               3, 1, 6,    // unit 3 (no mixNext)
                               3, 6,       // unit 1 repeat / end period
                               2,          // trigger delay
                               3,          // auto-play delay
                              };

#define PERIOD_MIN 0.5f
#define PERIOD_MAX 2.0f

#define PERIOD_ACCELERATE_MIN 0.5f
#define PERIOD_ACCELERATE_MAX 2.0f

#define MIX_NEXT_MIN 0.5f
#define MIX_NEXT_MAX 1.0f

/**
 * Globals.
 */

/// The sound player..
SoundPlayer player;

/// IR remote receiver.
IRrecv irrecv(IR_IN);

/// Millisecond counter.
unsigned long __controlCounter = 0;
unsigned long controlMillis() {
  return (__controlCounter * 1000UL) / CONTROL_RATE;
}

/// Timer for trigger delay.
SuperTimer triggerTimer(false, controlMillis);
unsigned long triggerDelay;

/// Timer for auto-play delay.
SuperTimer autoPlayTimer(false, controlMillis);
unsigned long autoPlayDelay;

/// Timer for silent mode delay.
SuperTimer silentModeTimer(false, controlMillis);

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
int distanceDNA(const BinaryChromosome& c1, const BinaryChromosome& c2);

/// Adds a sound unit to player starting from start gene.
void addUnitFromDNA(int startGene, bool hasMixNext=true);

/// Init random seed using analog pin.
void initRandomSeed(int analogPin);

/// Generates a hascode from IR remote code.
uint64_t hash(const decode_results& result);

/// Transfers decoded IR message to DNA code.
void decodeResultsToDNA(uint8_t* code, const decode_results& result);

/// Resets sound player based on current DNA.
void resetPlayerFromDNA(bool restart=true);

/// Setup.
void setup() {
  // Init indicator LED.
  pinMode(INDICATOR_LED_OUT, OUTPUT);
  digitalWrite(INDICATOR_LED_OUT, HIGH);

  // Init random.
  initRandomSeed(RANDOM_AIN);

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

  // Init timers.
  triggerTimer.start();
  triggerDelay = 0;

  autoPlayTimer.reset();
  autoPlayDelay = 0;

  silentModeTimer.start();

  // Small delay.
  delay(100);

  // Switch LED off.
  digitalWrite(INDICATOR_LED_OUT, LOW);
}

/// Mozzi update control.
void updateControl() {

  // Check for incoming message.
  static decode_results results;
  if (irrecv.decode(&results))
  {
    // Switch LED on.
    digitalWrite(INDICATOR_LED_OUT, HIGH);

    if (results.value != REPEAT) {
      Serial << "Value:" << results.value <<endl;
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

      // Start trigger timer.
      triggerDelay = map(dna.getGeneValue(GENE_TRIGGER_DELAY), 0, dna.maxGeneValue(GENE_TRIGGER_DELAY), TRIGGER_DELAY_MIN, TRIGGER_DELAY_MAX);
      triggerDelay += random(-TRIGGER_DELAY_NOISE, TRIGGER_DELAY_NOISE);
      triggerDelay = constrain(triggerDelay, TRIGGER_DELAY_MIN, TRIGGER_DELAY_MAX);
      triggerTimer.start();

      // Restart auto-play timer.
      autoPlayDelay = map(dna.getGeneValue(GENE_AUTO_PLAY_DELAY), 0, dna.maxGeneValue(GENE_AUTO_PLAY_DELAY), AUTO_PLAY_DELAY_MIN, AUTO_PLAY_DELAY_MAX);
      autoPlayDelay += random(-AUTO_PLAY_DELAY_NOISE, AUTO_PLAY_DELAY_NOISE);
      autoPlayDelay = constrain(autoPlayDelay, AUTO_PLAY_DELAY_MIN, AUTO_PLAY_DELAY_MAX);
      autoPlayTimer.start();

      // Restart silent mode timer.
      silentModeTimer.start();
//      Serial << "Restart timer " << triggerTimer._startTime << " " << triggerTimer._offset << endl;
    }

    // Get ready to receive the next IR-remote signal.
    irrecv.resume();

    // Switch LED off.
    digitalWrite(INDICATOR_LED_OUT, LOW);
  }

  // Auto-play.
  else if (silentModeTimer.currentTime() < SILENT_MODE_DELAY &&
           (autoPlayTimer.isStarted() && autoPlayTimer.currentTime() > autoPlayDelay))
  {
    Serial << "AUTOPLAY" <<endl;
    // Mutate.
    dna.mutate(MUTATE_RATE);

    // Reset player params from new DNA and restart it.
    resetPlayerFromDNA();

    // Cancel trigger.
    triggerTimer.reset();

    // Restart auto-play timer.
    autoPlayDelay = map(dna.getGeneValue(GENE_AUTO_PLAY_DELAY), 0, dna.maxGeneValue(GENE_AUTO_PLAY_DELAY), AUTO_PLAY_DELAY_MIN, AUTO_PLAY_DELAY_MAX);
    autoPlayDelay += random(-AUTO_PLAY_DELAY_NOISE, AUTO_PLAY_DELAY_NOISE);
    autoPlayDelay = constrain(autoPlayDelay, AUTO_PLAY_DELAY_MIN, AUTO_PLAY_DELAY_MAX);
    autoPlayTimer.start();

    // Start sound now.
    player.start();
  }

  // Check if we need to start playing (trigger delay).
  else if (triggerTimer.isStarted() && triggerTimer.currentTime() > triggerDelay)
  {
    // Start sound now.
    player.start();

    // Reset timer.
    triggerTimer.reset();
  }


  // Update control counter.
  __controlCounter++;
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

Sleep sleep;

/// Loop.
void loop() {
	if (silentModeTimer.currentTime() >= 5000) {
		sleep.pwrDownMode();
		sleep.sleepDelay(64);
	}
	else
  	audioHook();
}

/// Bit distance between two chromosomes.
int distanceDNA(const BinaryChromosome& c1, const BinaryChromosome& c2) {
  int diff = 0;
  unsigned int bit = info.bitSize();
  while (bit--)
    diff += (arrayBitRead(c1.code, bit) != arrayBitRead(c2.code, bit) ? 1 : 0);
  return diff;
}

/// Adds a sound unit to player starting from start gene.
void addUnitFromDNA(int startGene, bool hasMixNext) {
  int geneId         = startGene++;
  int genePeriodSign = startGene++;
  int genePeriod     = startGene++;
  int geneMixNext    = startGene++;

  uint8_t id = dna.getGeneValue(geneId);
  int sign = dna.getGeneValue(genePeriodSign) ? +1 : -1;
  float period = mapReal(dna.getGeneValue(genePeriod), 0, dna.maxGeneValue(genePeriod), PERIOD_MIN, PERIOD_MAX);
  period *= period;
  period *= sign;
  float mixNext;
  if (hasMixNext)
    mixNext = mapReal(dna.getGeneValue(geneMixNext), 0, dna.maxGeneValue(geneMixNext), MIX_NEXT_MIN, MIX_NEXT_MAX);
  else
    mixNext = 1.0f;

  player.addUnit(id, period, mixNext);
}

// Temporary struct to hold IR messages before transferring them to code.
struct __decode_results_code {
  uint32_t value;
  uint16_t panasonicAddress : 12;
  int8_t  decodeType : 4;
};

void initRandomSeed(int analogPin) {
#define __INIT_RANDOM_SEED_PRIME 331
#define __INIT_RANDOM_SEED_N_SAMPLES 1000
  int seed = 0;
  for (int i=0; i<__INIT_RANDOM_SEED_N_SAMPLES; i++)
    seed = (seed * __INIT_RANDOM_SEED_PRIME + analogRead(analogPin));
  randomSeed(seed);
}

uint64_t hash(const decode_results& result) {
//#define __HASH_PRIME 31
#define __HASH_PRIME 331
  uint64_t hash = 0;
  uint64_t n    = (1ULL << info.bitSize()); // n different values in DNA string

  __decode_results_code rc;
  rc.value            = result.value;
  rc.panasonicAddress = result.panasonicAddress + result.value; // we mix both because we won't have panasonic address often
  rc.decodeType       = result.decode_type == UNKNOWN ? 0 : result.decode_type;

  uint8_t* ptr = (uint8_t*)&rc;
  for (int i = 0; i<sizeof(__decode_results_code); i++)
    hash = (__HASH_PRIME * hash + *ptr++) % n;

  return hash;
}

/// Transfers decoded IR message to DNA code.
void decodeResultsToDNA(uint8_t* code, const decode_results& result) {
  __decode_results_code rc;
  rc.value            = result.value;
  rc.panasonicAddress = result.panasonicAddress + result.value; // we mix both because we won't have panasonic address often
  rc.decodeType       = result.decode_type == UNKNOWN ? 0 : result.decode_type;

  // DNA is shorter than remote code.
  if (info.byteSize() <= sizeof(rc)) {
    // Initialize code to zero.
    memset(code, 0, info.byteSize());

    uint8_t* ptr = (uint8_t*)&rc;
    for (int i = 0; i<sizeof(__decode_results_code); i++)
      code[i % info.byteSize()] += *ptr++;
  }
  // DNA is longer than remote code.
  else {
    uint8_t* ptr = (uint8_t*)&rc;
    for (int i = 0; i<info.byteSize(); i++)
      code[i] = ptr[i % sizeof(__decode_results_code)];
  }
}

/// Resets sound player based on current DNA.
void resetPlayerFromDNA(bool restart) {
  // Reset player.
  player.reset();

  // Add unit based on genes.
  addUnitFromDNA(GENE_UNIT_1_ID);
  if (dna.getGeneValue(GENE_HAS_UNIT_2))
  {
    addUnitFromDNA(GENE_UNIT_2_ID);
    if (dna.getGeneValue(GENE_HAS_UNIT_3))
    {
      addUnitFromDNA(GENE_UNIT_3_ID, false);
    }
  }

  // Possibly repeat unit 1.
  else if (dna.getGeneValue(GENE_UNIT_1_REPEAT) > 0)
  {
    // Handler to first added unit.
    SoundUnit& unit = player.units[0];
    unit.mixNext = constrain(unit.mixNext, 0.5, 0.8); // to avoid just playing same sound on top of one another

    // N. repetitions.
    int nRepeat = dna.getGeneValue(GENE_UNIT_1_REPEAT);
    Serial << "N repeat: " << nRepeat << endl;
    // This adjusts the periods in relation to the number of repetitions: if there are more repetitions each
    // sound will be slightly shorter.
    float periodAccelerateFactor = mapReal(nRepeat, 1, dna.maxGeneValue(GENE_UNIT_1_REPEAT),
                                                    1.0f, 0.5f);
    // Start and end period (adjusted).
    float startPeriod = unit.period * periodAccelerateFactor;
    float endPeriod   = mapReal(dna.getGeneValue(GENE_UNIT_1_REPEAT_END_PERIOD),
                                0, dna.maxGeneValue(GENE_UNIT_1_REPEAT_END_PERIOD),
                                PERIOD_MIN, PERIOD_MAX) * periodAccelerateFactor;
    // End and start period have same sign.
    if (startPeriod < 0)
      endPeriod *= -1.0f;

    // Reset first unit period.
    unit.period = startPeriod;

    // Add units repeatedly, updating period each time.
    for (int i=0; i<nRepeat; i++)
    {
      float period = mapReal(i+1, 0, nRepeat, startPeriod, endPeriod);
      player.addUnit(unit.id, period, unit.mixNext);
    }
  }
}
