#ifndef Gray_h
#define Gray_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../Demux.h"
#include "../../StateMachine.h"
#include "State.h"
#include "../StateUtils.h"
#include "../libs/Utils.h"

extern Display display;
extern Demux demux;

extern StateMachine stateMachine;
extern State *welcomeState;
extern State *borderState;

extern char educatorTruthTable[16];
extern int variableSize;
extern int columnSize;
extern int rowSize;

class Gray : public State {
  public:
    void onTick() override;
    void onEnter() override;
    void onPressButtonA() override;
    void onPressButtonB() override;
    void onPressButtonC() override;
    void onPressButtonD() override;
    void show() override;
  private:
    int currentIndex;
    bool checkStudentInput(int row, int col, bool shouldOutputSuccess);
    Timer timer = Timer(2500);
};

#endif