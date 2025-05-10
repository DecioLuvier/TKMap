#include "Display.h"
#include "Demux.h"
#include "StateMachine.h"
#include "src/states/State.h"
#include "src/states/Welcome.h"
#include "src/states/Preparation.h"
#include "src/states/Truth.h"
#include "src/states/Gray.h"
#include "src/states/Border.h"
#include "src/states/Algebra.h"
#include "src/states/End.h"

Display display;
Demux demux;

StateMachine stateMachine;
Truth truth;
Preparation preparation;
Welcome welcome;
Gray gray;
Border border;
Algebra algebra;
End end;

//  References to switch states
State *truthState = &truth;
State *preparationState = &preparation;
State *welcomeState = &welcome;
State *grayState = &gray;
State *borderState = &border;
State *algebraState = &algebra;
State *endState = &end;

// Variables shared between states
set_t studentPrimeSet;
char educatorTruthTable[16] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
char targetSet[5] = {'0', '0', '0', '0', '0'};
int variableSize = 4;
int columnSize = 4;
int rowSize = 4;

void setup() {
  Serial.begin(9600);
  display.begin();
  demux.begin();
  stateMachine.begin();
  stateMachine.setState(welcomeState, true);
}

void loop() {
  stateMachine.tick();
}
