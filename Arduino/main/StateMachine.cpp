#include "StateMachine.h"

void StateMachine::begin() {
  pinMode(BUTTON_MATRIX_A, INPUT_PULLUP);
  pinMode(BUTTON_MATRIX_B, INPUT_PULLUP);
  pinMode(BUTTON_MATRIX_C, INPUT_PULLUP);
  pinMode(BUTTON_MATRIX_D, INPUT_PULLUP);
}

void StateMachine::setState(State *state, bool triggerOnEnter) {
  if (currentState != nullptr)
    currentState->onExit();
  currentState = state;
  if (triggerOnEnter)
    currentState->onEnter();
  currentState->show();
}

void StateMachine::tick() {
  buttonA.tick();
  buttonB.tick();
  buttonC.tick();
  buttonD.tick();
  currentState->onTick();
  if (buttonA.wasPressed())
    currentState->onPressButtonA();
  else if (buttonB.wasPressed())
    currentState->onPressButtonB();
  else if (buttonC.wasPressed())
    currentState->onPressButtonC();
  else if (buttonD.wasPressed())
    currentState->onPressButtonD();
}
