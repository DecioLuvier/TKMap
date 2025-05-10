#ifndef Button_h
#define Button_h

#include <Arduino.h>

#define DEBOUNCE_TIME 150

class Button {
  public:
    Button(int pin);
    void tick();
    bool wasPressed();
  private:
    bool isReady;
    int pin;
    unsigned long initialTime;
    unsigned long currentTime;
    bool isDetecting;
};

#endif