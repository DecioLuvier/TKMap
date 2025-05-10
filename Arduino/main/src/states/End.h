#ifndef End_h
#define End_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../StateMachine.h"
#include "../Types.h"
#include "State.h"
#include "../StateUtils.h"
#include "../libs/QuineMcCluskey.h"
#include "../libs/PetrickMethod.h"

extern Display display;

extern StateMachine stateMachine;
extern State *welcomeState;
extern State *borderState;

extern set_t studentPrimeSet;
extern char educatorTruthTable[16];
extern int variableSize;

class End : public State {
  public:
    void onEnter() override;
    void onPressButtonA() override;
    void onPressButtonC() override;
    void onPressButtonD() override;
    void show() override;
  private:
    bool isShowingUserAnswer;
};

#endif