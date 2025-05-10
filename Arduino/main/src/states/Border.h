#ifndef Border_h
#define Border_h

#include <Arduino.h>
#include "../../Display.h"
#include "../../Demux.h"
#include "../../StateMachine.h"
#include "../Types.h"
#include "State.h"
#include "../StateUtils.h"
#include "../libs/QuineMcCluskey.h"
#include "../libs/Utils.h"

extern Display display;
extern Demux demux;

extern StateMachine stateMachine;
extern State *grayState;
extern State *algebraState;
extern State *endState;

extern set_t studentPrimeSet;
extern char educatorTruthTable[16];
extern char targetSet[5];
extern int variableSize;
extern int columnSize;
extern int rowSize;

enum class Direction { TOP, RIGHT, BOTTOM, LEFT };

class Border : public State {
  public:
    void onTick() override;
    void onEnter() override;
    void onPressButtonA() override;
    void onPressButtonB() override;
    void onPressButtonC() override;
    void onPressButtonD() override;
    void show() override;
  private:
    int getBorderIndex(int row, int col, Direction dir);
    Timer timer = Timer(2500);
};

#endif