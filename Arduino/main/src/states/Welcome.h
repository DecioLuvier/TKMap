#ifndef Welcome_h
#define Welcome_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../StateMachine.h"
#include "State.h"
#include "../StateUtils.h"
#include "../libs/Utils.h"

extern Display display;

extern StateMachine stateMachine;
extern State *preparationState;
extern State *grayState;

class Welcome : public State {
  public:
    void onEnter() override;
    void onPressButtonA() override;
    void onPressButtonC() override;
    void onPressButtonD() override;
    void show() override;
  private:
    int currentCredit;
};

#endif
