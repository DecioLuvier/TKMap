#ifndef Preparation_h
#define Preparation_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../StateMachine.h"
#include "State.h"
#include "../StateUtils.h"
#include "../libs/Utils.h"

extern Display display;

extern StateMachine stateMachine;
extern State *truthState;
extern State *welcomeState;

extern int variableSize;
extern int columnSize;
extern int rowSize;

class Preparation : public State {
  public:
    void onExit() override;
    void onPressButtonA() override;
    void onPressButtonB() override;
    void onPressButtonD() override;
    void show() override;
};

#endif
