//#include <ADC.h>  // Teensy 3.0/3.1 uncomment this line and install http://github.com/pedvide/ADC
#include <MozziGuts.h>
#include <mozzi_fixmath.h>
#include <Sample.h>
#include <Streaming.h>

#include <qualia/ga/BinaryChromosome.h>
#include <qualia/util/map.h>

#include "SoundPlayer.h"

#define CONTROL_RATE 64

#define SERIAL_IR Serial1
#define SERIAL_IR_BAUDRATE 9600

#define INDICATOR_LED_OUT 30

#define MUTATE_RATE 0.05f

/// The sound player..
SoundPlayer player;

int index; // ???

//struct SoundUnitParams {
//  uint8_t      id  : 2; // 0..3
//  uint8_t  period  : 4; // 0..15
//  uint8_t  mixNext : 2; // 0..3
//};

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

const uint8_t GENE_SIZES[] = { 2, 1, 4, 4,
                               1,
                               2, 1, 4, 4,
                               1,
                               2, 1, 4, 4,
                              };

BinaryChromosomeProperties info(N_GENES, GENE_SIZES);
BinaryChromosome            dna(&info);
BinaryChromosome            messageDna(&info);
BinaryChromosome            offspring1(&info);
BinaryChromosome            offspring2(&info);

void addUnitFromDNA(int startGene) {
  int geneId         = startGene++;
  int genePeriodSign = startGene++;
  int genePeriod     = startGene++;
  int geneMixNext    = startGene++;

  uint8_t id = dna.getGeneValue(geneId);
  float period = dna.getGeneValue(genePeriodSign) ? +1 : -1;
  period *= mapReal(dna.getGeneValue(genePeriod), 0, dna.maxGeneValue(genePeriod), 0.5f, 3.0f);
  float mixNext = mapReal(dna.getGeneValue(geneMixNext), 0, dna.maxGeneValue(geneMixNext), 0, 1);

  player.addUnit(id, period, mixNext);
}

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

void setup() {
  Serial.begin(9600);
  SERIAL_IR.begin(SERIAL_IR_BAUDRATE);

  dna.init();
  messageDna.init();

  startMozzi();

  resetPlayerFromDNA();
}

int serialReadInt() {
  return Serial.read() - '0';
}

void updateControl(){
  if (SERIAL_IR.available() >= info.byteSize()) {
    Serial << SERIAL_IR.available() << endl;
    // Generate a DNA string using serial information.
    for (int i=0; i<info.byteSize(); i++) {
      messageDna.code[i] = (uint8_t)SERIAL_IR.read();
      Serial << (int) messageDna.code[i]<< " ";
    }
    Serial.println();

    // Generate offsprings.
    BinaryChromosome::crossoverTwoPoint(dna, messageDna, &offspring1, &offspring2);

    // Choose one of the offsprings.
//    dna.copyFrom( random(2) ? offspring1 : offspring2 );
    dna.copyFrom(messageDna);

    resetPlayerFromDNA();
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

int updateAudio() {
  if (player.hasNext()) {
    return player.next();
  }
  else {
    return 0;
  }
}

void loop() {
  audioHook();
}
