#include "Timer.h"

Timer::Timer(unsigned long interval) {
  this->interval = interval;
  this->isRunning = false;
  this->isReady = false;
  this->initialTime = 0;
  this->currentTime = 0;
}

bool Timer::hasElapsed() {
  if (isReady) {
    isReady = false;
    isRunning = false;
    return true;
  }
  return false;
}

void Timer::tick() {
  if (!isRunning)
    return;
  currentTime = millis();
  if (currentTime - initialTime >= interval) {
    isReady = true;
    isRunning = false;
  }
}

void Timer::start() {
  reset();
  isRunning = true;
}

void Timer::stop() {
  isRunning = false;
}

void Timer::reset() {
  initialTime = millis();
  currentTime = initialTime;
  isReady = false;
}