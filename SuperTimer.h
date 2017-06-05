/*
 * SuperTimer class
 * Counts the time passed since started. With extra functionalities added, such
 * as the possibility to pause/resume and specifically add time to the timer.
 * 
 * (c) 2008 Sofian Audry | info(@)sofianaudry(.)com
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
#ifndef SUPER_TIMER_INC
#define SUPER_TIMER_INC

/*
 * Example code (see "Timer.h" for basic usage):
 * 
 * SuperTimer timer;
 * timer.start();
 * // do some stuff
 * timer.pause();
 * // do more stuff
 * timer.resume();
 * // do some "out of the clock" processing, such as shutting the power down using
 * // the watchdog for 8000 ms
 * timer.addTime(8000); // add the time that wasn't accounted for
 */
class SuperTimer {
public:
  unsigned long _startTime;
  unsigned long _offset;
  bool _started;
  unsigned long (*_millisFunc)(void);

public:
  SuperTimer(bool startNow = false, unsigned long (*millisFunc)(void)=millis)
    : _startTime(0), _offset(0), _started(false), _millisFunc(millisFunc) {
    reset(startNow);
  }

  bool isStarted() const { return _started; }

  void reset(bool startNow=false) {
    _startTime = _millisFunc();
    _offset = 0;
    _started = startNow;
  }

  void start() {
    reset(true);
  }
  
  void pause() {
    _offset = currentTime();
    _started = false;
  }
  
  void resume() {
    _startTime = _millisFunc();
    _started = true;
  }
  
  void addTime(unsigned long offset) {
    _offset += offset;
  }
  
  void stop() {
    _started = false;
  }
  
  bool isStarted() {
    return _started;
  }
  
  unsigned long currentTime() {
    return _offset + (_millisFunc() - _startTime);
  }
  
};

#endif
