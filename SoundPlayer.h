/*
 * SoundPlayer.h
 *
 * (c) 2014 Sofian Audry -- info(@)sofianaudry(.)com
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SOUNDPLAYER_H_
#define SOUNDPLAYER_H_

#include <MozziGuts.h>
#include <mozzi_fixmath.h>
#include <Sample.h>

#define USE_8K_AUDIO

#ifdef USE_8K_AUDIO

#include "oiseau_1_8k.h"
#include "crow_1_8k.h"
#include "owl_1_8k.h"
#include "seagull_1_8k.h"
#include "tui_1_8k.h"
//#include "woodpecker_1_8k.h"

#include "cats_1_8k.h"
#include "phone_1_8k.h"

#define SAMPLE_AUDIO_RATE 8000
//#define OISEAU_1_DATA OISEAU_1_8K_DATA
//#define OISEAU_1_NUM_CELLS OISEAU_1_8K_NUM_CELLS
//#define CROW_1_DATA CROW_1_8K_DATA
//#define CROW_1_NUM_CELLS CROW_1_8K_NUM_CELLS
//#define OWL_1_DATA OWL_1_8K_DATA
//#define OWL_1_NUM_CELLS OWL_1_8K_NUM_CELLS
//#define TUI_1_DATA TUI_1_8K_DATA
//#define TUI_1_NUM_CELLS TUI_1_8K_NUM_CELLS

static Sample <SEAGULL_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    seagull1(SEAGULL_1_8K_DATA);
static Sample <OWL_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>        owl1(OWL_1_8K_DATA);

static Sample <CROW_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>       crow1(CROW_1_8K_DATA);
static Sample <TUI_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>        tui1(TUI_1_8K_DATA);
static Sample <OISEAU_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>     oiseau1(OISEAU_1_8K_DATA);
//static Sample <WOODPECKER_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR> woodpecker1(WOODPECKER_1_8K_DATA);

static Sample <CATS_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>       cats1(CATS_1_8K_DATA);
static Sample <PHONE_1_8K_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>      phone1(PHONE_1_8K_DATA);


//static Sample <TUI_2_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    tui2(TUI_2_DATA);
//static Sample <RAVEN_ARH_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    owl1(RAVEN_ARH_DATA);

enum {
  SEAGULL_1,
  OWL_1,

  CROW_1,
  TUI_1,
  OISEAU_1,
//  TUI_2,
//  WOODPECKER_1,
  CATS_1,
  PHONE_1,

  N_SAMPLES,
};

const Q15n0 SAMPLE_NUM_CELLS[] = {
    SEAGULL_1_8K_NUM_CELLS,
    OWL_1_8K_NUM_CELLS,

    CROW_1_8K_NUM_CELLS,
    TUI_1_8K_NUM_CELLS,
    OISEAU_1_8K_NUM_CELLS,

    CATS_1_8K_NUM_CELLS,
    PHONE_1_8K_NUM_CELLS,
//    WOODPECKER_1_8K_NUM_CELLS,
//  TUI_2_NUM_CELLS,
//  RAVEN_ARH_NUM_CELLS,
};

#else
// The samples.
#include "oiseau_1.h"
#include "crow_1.h"
//#include <samples/raven_arh_int8.h>
#include "owl_1.h"
#include "tui_1.h"
//#include "tui_2.h"
#define SAMPLE_AUDIO_RATE AUDIO_RATE

//static Sample <OISEAU_1_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR> oiseau1(OISEAU_1_DATA);
static Sample <CROW_1_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>   crow1(CROW_1_DATA);
//static Sample <OWL_1_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>   crow1(OWL_1_DATA);
static Sample <OWL_1_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    owl1(OWL_1_DATA);
static Sample <TUI_1_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    tui1(TUI_1_DATA);
//static Sample <TUI_2_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    tui2(TUI_2_DATA);
//static Sample <RAVEN_ARH_NUM_CELLS, SAMPLE_AUDIO_RATE, INTERP_LINEAR>    owl1(RAVEN_ARH_DATA);

enum {
//  OISEAU_1,
  CROW_1,
  OWL_1,
  TUI_1,
//  TUI_2,
  N_SAMPLES,
};

const Q15n0 SAMPLE_NUM_CELLS[] = {
//  OISEAU_1_NUM_CELLS,
  CROW_1_NUM_CELLS,
  OWL_1_NUM_CELLS,
  TUI_1_NUM_CELLS,
//  TUI_2_NUM_CELLS,
//  RAVEN_ARH_NUM_CELLS,
};

#endif


#define DEFAULT_SAMPLE_ID 0

static Q15n0 sampleNumCells(uint8_t id) {
  id %= N_SAMPLES;
  return SAMPLE_NUM_CELLS[id];
}

static int getSampleAtIndex(uint8_t id, Q15n0 index) {
  // Serial.print(id); Serial.print(" "); Serial.println(index);
  id %= N_SAMPLES;

  switch (id) {

  case SEAGULL_1:     return (int)seagull1.atIndex(index);    break;
  case OWL_1:         return (int)owl1.atIndex(index);        break;

  case CROW_1:        return (int)crow1.atIndex(index);       break;
  case TUI_1:         return (int)tui1.atIndex(index);        break;
  case OISEAU_1:      return (int)oiseau1.atIndex(index);     break;

  case CATS_1:        return (int)cats1.atIndex(index);       break;
  case PHONE_1:       return (int)phone1.atIndex(index);      break;
  default:            return 0;

//    case OISEAU_1:      return (int)oiseau1.atIndex(index);     break;
//    case CROW_1:        return (int)crow1.atIndex(index);       break;
//    case WOODPECKER_1:  return (int)woodpecker1.atIndex(index); break;
//    case TUI_2:    return (int)tui2.atIndex(index);    break;
//    default:            return DEFAULT_SAMPLE.atIndex(index);
  }
}

/// Represents a unit of sound, as defined by a sound sample and a set of playback parameters.
struct SoundUnit {

  /// the sample ID
  uint8_t id;

  /// as proportion of base period (neg. = reverse)
  float   period;

  /**
   * in [0,1] : proportion of this unit that should be mixed with next unit
   * 0 = next unit will be played right after current unit
   * 1 = next unit will start at the same time as current unit
   */
  float   mixNext;

  /// Default constructor.
  SoundUnit() : id(DEFAULT_SAMPLE_ID), period(1), mixNext(0) {}
};

#define MAX_SOUND_UNITS 8

/// Represents a player that can mix different sounds one after the other.
class SoundPlayer {
public:
  /// Number of sound units to be mixed.
  int nUnits;

  /// The sound units.
  SoundUnit units[MAX_SOUND_UNITS];

  // Internal use.
  int _unit;   // current unit
  int _unitId; // current unit id

  Q15n16 _position; // current position
  boolean _forward; // is the current unit played forward (or reverse)?
  Q15n16 _inc;      // increment to apply at each next() call
  long _mixSteps;   // mix with next unit
  Q15n16 _numCells; // num cells of current unit

  int _nextUnitId;       // id of next unit
  Q15n16 _nextPosition;  // position of next unit (for mixes)
  boolean _nextForward;  // position of next unit (for mixes)
  Q15n16 _nextInc;       // position of next unit (for mixes)
  Q15n16 _nextNumCells;  // num cells of current unit

  SoundPlayer();

  /// Removes all sound units.
  void reset();

  /// Adds a unit.
  void addUnit(uint8_t id, float period=1.0f, float mixNext=0.0f);

  /// Starts the playback.
  void start();

  /// Returns next sound element.
  inline int next() {
    // Check if we need to switch to the next sound unit.
    if (!_unitHasNext()) {
      _unit++;
      _unit %= nUnits;
      _startUnit(_unit);
    }
    // Return next element in the unit.
    if (_mixSteps > 0) {
      _mixSteps--;
      // Just the sample.
      return getSampleAtIndex(_unitId, Q15n16_to_Q15n0(_position+=_inc));
    }
    else {
      // Mix of current sample and next sample.
      return (getSampleAtIndex(_unitId, Q15n16_to_Q15n0(_position+=_inc)) + getSampleAtIndex(_nextUnitId, Q15n16_to_Q15n0(_nextPosition+=_nextInc))) >> 1;
    }
  }

  /// Is there a next element to be played?
  inline bool hasNext() {
    return (_unit < nUnits-1 || _unitHasNext());
  }

  /// Returns true iff current unit has a next element.
  inline bool _unitHasNext() {
    return (_forward ? _position < _numCells : _position > 0);
  }

  /// Sets current unit and starts it.
  // TODO: we should precompute everything
  void _startUnit(int u);
};

#endif /* SOUNDPLAYER_H_ */
