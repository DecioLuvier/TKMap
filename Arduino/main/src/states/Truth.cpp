#include "Truth.h"

void Truth::onEnter() {
  currentIndex = 0;
}

void Truth::onPressButtonB() {
  StateUtils::toggleTruthTableValue(&educatorTruthTable[currentIndex]);
  show();
}

void Truth::onPressButtonC() {
  StateUtils::wrapIndexInRange(&currentIndex, 1, 0, (1 << variableSize) - 1);
  show();
}

void Truth::onPressButtonD() {
  stateMachine.setState(welcomeState, true);
}

void Truth::show() {
  char selectedVariables[5] = "";
  strncat(selectedVariables, "ABCD", variableSize);
  char currentIndexBinary[5] = "";
  Utils::decimalToBinary(currentIndex, currentIndexBinary, variableSize);
  char currentIndexTerm[20] = "";
  StateUtils::indexToChar(educatorTruthTable[currentIndex], currentIndexTerm);
  char buffer[200] = "";
  sprintf(buffer, "%s\n%s(%d) %s", selectedVariables, currentIndexBinary, currentIndex + 1, currentIndexTerm);
  display.show(buffer);
}
