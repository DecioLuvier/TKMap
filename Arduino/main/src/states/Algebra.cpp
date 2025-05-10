#include "Algebra.h"

void Algebra::onTick() {
  timer.tick();
  if (timer.hasElapsed())
    show();
}

void Algebra::onEnter() {
  currentVariable = 0;
  for (int i = 0; i < variableSize; i++)
    studentSet[i] = '0';
  studentSet[variableSize] = '\0';
  show();
}

void Algebra::onPressButtonA() {
  timer.stop();
  stateMachine.setState(borderState, false);
}

void Algebra::onPressButtonB() {
  timer.stop();
  StateUtils::toggleTruthTableValue(&studentSet[currentVariable]);
  show();
}

void Algebra::onPressButtonC() {
  timer.stop();
  StateUtils::wrapIndexInRange(&currentVariable, 1, 0, variableSize - 1);
  show();
}

void Algebra::onPressButtonD() {
  timer.stop();
  if (strcmp(targetSet, studentSet) == 0) {
    strcpy(studentPrimeSet.terms[studentPrimeSet.size], studentSet), studentPrimeSet.size++;
    stateMachine.setState(borderState, false);
    return;
  }
  display.show("Expression does not\nmatch the island"), timer.start();
}

void Algebra::show() {
  char expression[20] = "";
  for (int i = 0; i < variableSize; i++) {
    if (studentSet[i] == '0' || studentSet[i] == '1')
      strncat(expression, &"ABCD"[i], 1);
    else
      strcat(expression, "x");
    if (studentSet[i] == '0')
      strcat(expression, "'");
    else
      strcat(expression, " ");
  }

  char selectedVariableArrow[20] = "";
  for (int i = 0; i < currentVariable; i++)
    strcat(selectedVariableArrow, "  ");
  strcat(selectedVariableArrow, "^");

  char buffer[200] = "";
  sprintf(buffer, "%s\n%s", expression, selectedVariableArrow);
  display.show(buffer);
}
