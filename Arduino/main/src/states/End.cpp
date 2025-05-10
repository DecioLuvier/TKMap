#include "end.h"

void End::onEnter() {
  isShowingUserAnswer = true;
}

void End::onPressButtonA() {
  stateMachine.setState(borderState, true);
}

void End::onPressButtonC() {
  isShowingUserAnswer = !isShowingUserAnswer;
  show();
}

void End::onPressButtonD() {
  stateMachine.setState(welcomeState, true);
}

void End::show() {
  QuineMcCluskey quineMcCluskey(educatorTruthTable, variableSize);
  PetrickMethod educator(&quineMcCluskey.onSet, &quineMcCluskey.primeSet, variableSize);

  bool solutionIsCorrect = educator.isSetInSolutions(studentPrimeSet);
  bool solutionIsValid = false;

  if (studentPrimeSet.size == 0 && educator.sumOfProducts.size == 0)
    solutionIsCorrect = true;
  if (solutionIsCorrect == false) {
    PetrickMethod studentSolution(&quineMcCluskey.onSet, &studentPrimeSet, variableSize);
    if (studentSolution.sumOfProducts.size != 0)
      solutionIsValid = educator.isSetInSolutions(studentSolution.sumOfProducts.solution[0]);
  }

  char statusMessage[50] = "";
  if (solutionIsCorrect)
    strcpy(statusMessage, "Correct solution\nOptimized\n\n");
  else if (solutionIsValid)
    strcpy(statusMessage, "Valid solution\nBut not optimized\n\n");
  else
    strcpy(statusMessage, "Invalid solution\n\n\n");

  char solutionType[50] = "";

  if (isShowingUserAnswer)
    strcpy(solutionType, "Your Solution:\n");
  else
    strcpy(solutionType, "Expected Solution:\n");

  char buffer[200] = "";
  strcpy(buffer, statusMessage);
  strcat(buffer, solutionType);

  if (isShowingUserAnswer) {
    if (studentPrimeSet.size == 0)
      strcat(buffer, "False");
    else if (studentPrimeSet.size == 1 && (strcmp(studentPrimeSet.terms[0], "xxxx") == 0))
      strcat(buffer, "True");
    else
      StateUtils::formatPrimeSet(variableSize, &studentPrimeSet, buffer, false);
  }
  else {
    if (educator.sumOfProducts.solution[0].size == 0)
      strcat(buffer, "False");
    else if (educator.sumOfProducts.solution[0].size == 1 && (strcmp(educator.sumOfProducts.solution[0].terms[0], "xxxx") == 0))
      strcat(buffer, "True");
    else
      StateUtils::formatPrimeSet(variableSize, &educator.sumOfProducts.solution[0], buffer, false);
  }

  display.show(buffer);
}