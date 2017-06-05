/*
 * SoundPlayer.cpp
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

#include "SoundPlayer.h"

SoundPlayer::SoundPlayer() : nUnits(0) {
  for (int i=0; i<MAX_SOUND_UNITS; i++)
    units[i] = SoundUnit();
}

void SoundPlayer::reset() {
  nUnits = 0;
}

#include <Streaming.h>
void SoundPlayer::addUnit(uint8_t id, float period, float mixNext) {
  SoundUnit& unit = units[nUnits++];
//  Serial << "Adding unit: " << id << " " << period << " " << mixNext << endl;
  unit.id = id;
  unit.period = period;
  unit.mixNext = mixNext;
}

void SoundPlayer::start() {
  _startUnit(0);
}

void SoundPlayer::_startUnit(int u) {
  _unit = u;

  uint8_t id = units[u].id;
  int numCells = sampleNumCells(id);

  if (u == 0) {
    _unitId   = id;
    _forward  = units[u].period > 0;
    _inc      = float_to_Q15n16(SAMPLE_AUDIO_RATE/(units[u].period*AUDIO_RATE));
    _numCells = float_to_Q15n16(numCells);
    _position = (_forward ? 0 : _numCells-1);

//    Serial << _position << " " << numCells << " " << _numCells << endl;
  }
  else {
    _unitId   = _nextUnitId;
    _forward  = _nextForward;
    _inc      = _nextInc;
    _numCells = _nextNumCells;
    _position = _nextPosition; // might already have been changed
  }

  // For next mix.
  int nextU = u+1;
  if (nextU < nUnits) {
    _nextUnitId = units[nextU].id;
    int nextNumCells = sampleNumCells(_nextUnitId);
    _nextForward  = units[nextU].period > 0;
    _nextInc      = float_to_Q15n16(SAMPLE_AUDIO_RATE/(units[nextU].period*AUDIO_RATE));
    _nextNumCells = float_to_Q15n16(nextNumCells);
    _nextPosition = (_nextForward ? 0 : _nextNumCells-1);
    long nStepsCurrent = (numCells - (_forward ? _position : numCells-1-_position)) * abs(units[u].period);
    long nStepsNext    = nextNumCells * abs(units[nextU].period);
    long nStepsOfMix   = nStepsCurrent * units[u].mixNext;
    nStepsOfMix = min(nStepsOfMix, nStepsNext);
    _mixSteps = nStepsCurrent - nStepsOfMix;
    //      _mixSteps = min(numCells * abs(units[u].period), nextNumCells * abs(units[nextU].period)) * (1 - units[u].mixNext);
    //      Serial << _mixSteps << "/" << _numCells << " " << _inc << " " << _nextInc << " " << units[nextU].period << endl;
  }
  else
    _mixSteps = numCells * abs(units[u].period);
}
