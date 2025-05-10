#include "Preparation.h"

void Preparation::onExit() {
  columnSize = 1 << (variableSize / 2);
  rowSize = 1 << (variableSize / 2 + (variableSize % 2));
}

void Preparation::onPressButtonA() {
  stateMachine.setState(truthState, true);
}

void Preparation::onPressButtonB() {
  StateUtils::wrapIndexInRange(&variableSize, -1, 2, 4);
  show();
}

void Preparation::onPressButtonD() {
  stateMachine.setState(welcomeState, true);
}

void Preparation::show() {
  char buffer[200] = "";
  sprintf(buffer, "Select the board\npreferences\n\n\nVariables:\n-> %d", variableSize);
  display.show(buffer);
}