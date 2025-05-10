#ifndef State_h
#define State_h

#include <Arduino.h>

class State {
  public:
    virtual void onEnter() {};
    virtual void onTick() {};
    virtual void onExit() {};
    virtual void onPressButtonA() {};
    virtual void onPressButtonB() {};
    virtual void onPressButtonC() {};
    virtual void onPressButtonD() {};
    virtual void show() {};
};

#endif