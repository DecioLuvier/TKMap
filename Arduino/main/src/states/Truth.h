#ifndef Truth_h
#define Truth_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../StateMachine.h"
#include "State.h"
#include "../StateUtils.h"
#include "../libs/Utils.h"

extern Display display;

extern StateMachine stateMachine;
extern State *welcomeState;

extern int variableSize;
extern char educatorTruthTable[16];

class Truth : public State {
  public:
    void onEnter() override;
    void onPressButtonB() override;
    void onPressButtonC() override;
    void onPressButtonD() override;
    void show() override;
  private:
    int currentIndex;
};

#endif
