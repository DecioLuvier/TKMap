#ifndef StateMachine_h
#define StateMachine_h

#include <Arduino.h>
#include "src/states/State.h"
#include "src/libs/Button.h"

#define BUTTON_MATRIX_A 3
#define BUTTON_MATRIX_B 2
#define BUTTON_MATRIX_C 18
#define BUTTON_MATRIX_D 19

class StateMachine {
  public:
    void begin();
    void tick();
    void setState(State *state, bool triggerOnEnter);
  private:
    Button buttonA = Button(BUTTON_MATRIX_A);
    Button buttonB = Button(BUTTON_MATRIX_B);
    Button buttonC = Button(BUTTON_MATRIX_C);
    Button buttonD = Button(BUTTON_MATRIX_D);
    State *currentState = nullptr;
};

#endif