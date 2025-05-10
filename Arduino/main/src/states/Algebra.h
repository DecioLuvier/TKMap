#ifndef Algebra_h
#define Algebra_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../StateMachine.h"
#include "../Types.h"
#include "State.h"
#include "../StateUtils.h"

extern Display display;

extern StateMachine stateMachine;
extern State *borderState;

extern set_t studentPrimeSet;
extern char targetSet[5];
extern int variableSize;

class Algebra : public State {
  public:
    void onTick() override;
    void onEnter() override;
    void onPressButtonA() override;
    void onPressButtonB() override;
    void onPressButtonC() override;
    void onPressButtonD() override;
    void show() override;
  private:
    char studentSet[5];
    int currentVariable;
    Timer timer = Timer(2500);
};

#endif