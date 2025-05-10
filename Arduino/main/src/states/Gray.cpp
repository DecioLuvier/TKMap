#include "Gray.h"

void Gray::onTick() {
  timer.tick();
  if (timer.hasElapsed())
    show();
}

void Gray::onEnter() {
  currentIndex = 0;
}

void Gray::onPressButtonA() {
  timer.stop();
  stateMachine.setState(welcomeState, true);
}

void Gray::onPressButtonB() {
  timer.stop();
  int col = currentIndex % columnSize;
  int row = currentIndex / columnSize;
  checkStudentInput(row, col, true);
}

void Gray::onPressButtonC() {
  timer.stop();
  StateUtils::wrapIndexInRange(&currentIndex, 1, 0, (1 << variableSize) - 1);
  show();
}

void Gray::onPressButtonD() {
  timer.stop();
  for (int row = 0; row < 4; row++)
    for (int col = 0; col < 4; col++)
      if (checkStudentInput(row, col, false) == false)
        return;
  stateMachine.setState(borderState, true);
}

void Gray::show() {
  char educatorCurrentTerm[20] = "";
  StateUtils::indexToChar(educatorTruthTable[currentIndex], educatorCurrentTerm);
  char buffer[200] = "";
  sprintf(buffer, "Element: %d\nValue:   %s\n\n\nVariables:\n-> %d", currentIndex + 1, educatorCurrentTerm, variableSize);
  display.show(buffer);
}

bool Gray::checkStudentInput(int row, int col, bool shouldOutputSuccess) {
  char buffer[200] = "";

  int indexOnHardware = row * 4 + col;
  bool studentTrue = demux.readValue(mapTrue[indexOnHardware]);
  bool studentDontCare = demux.readValue(mapDontCare[indexOnHardware]);
  char studentInput = '0';
  if (studentTrue)
    studentInput = '1';
  else if (studentDontCare)
    studentInput = 'x';

  if (row >= rowSize || col >= columnSize) {
    if (studentInput == '0')
      return true;

    char value[20] = "";
    StateUtils::indexToChar(studentInput, value);
    sprintf(buffer, "Index out of the board.\nrow %d\ncolumn %d\nwas set as:\n%s", row + 1, col + 1, value);
    display.show(buffer);
    timer.start();
    return false;
  }

  int indexOnGrayCode = Utils::decimalToGrayCode(row) * columnSize + Utils::decimalToGrayCode(col);
  char educatorInput = educatorTruthTable[indexOnGrayCode];

  if (educatorInput == studentInput) {
    if (shouldOutputSuccess) {
      sprintf(buffer, "Index %d was valid", currentIndex + 1);
      display.show(buffer);
      timer.start();
    }
    return true;
  }

  char value1[20] = "";
  StateUtils::indexToChar(educatorInput, value1);
  char value2[20] = "";
  StateUtils::indexToChar(studentInput, value2);
  sprintf(buffer, "Error at index %d\n\nShould be\n-> %s\nwas set as:\n-> %s", indexOnGrayCode + 1, value1, value2);
  display.show(buffer);
  timer.start();
  return false;
}