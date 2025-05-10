#include "Button.h"

Button::Button(int pin) {
  this->pin = pin;
  this->initialTime = 0;
  this->currentTime = 0;
  this->isDetecting = false;
  this->isReady = false;
}

bool Button::wasPressed() {
  if (isReady) {
    isReady = false;
    isDetecting = false;
    return true;
  }
  return false;
}

void Button::tick() {
  if (digitalRead(pin)) {
    isDetecting = false;
    return;
  }

  if (!isDetecting) {
    initialTime = millis();
    isDetecting = true;
  }

  currentTime = millis();
  if (currentTime - initialTime >= DEBOUNCE_TIME)
    isReady = true;
}