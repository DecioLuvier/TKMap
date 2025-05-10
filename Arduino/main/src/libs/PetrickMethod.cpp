#include "PetrickMethod.h"

PetrickMethod::PetrickMethod(set_t *onSet, set_t *primeSet, int variableSize)
    : onSet(onSet), primeSet(primeSet), variableSize(variableSize) {
  sumOfProducts.size = 0;

  bool implicantChart[16][16] = {false};

  for (int i = 0; i < onSet->size; i++)
    for (int j = 0; j < primeSet->size; j++)
      if (isCovered(onSet->terms[i], primeSet->terms[j]))
        implicantChart[i][j] = true;

  int buffer[16];
  generateCombinations(0, buffer, 0, implicantChart);
}

bool PetrickMethod::isSetInSolutions(set_t &set) {
  for (int i = 0; i < sumOfProducts.size; i++)
    if (isSetEquivalent(sumOfProducts.solution[i], set))
      return true;
  return false;
}

bool PetrickMethod::isSetEquivalent(set_t &setA, set_t &setB) {
  if (setA.size != setB.size)
    return false;
  for (int i = 0; i < setA.size; i++) {
    bool found = false;
    for (int j = 0; j < setB.size; j++)
      if (strcmp(setA.terms[i], setB.terms[j]) == 0)
        found = true;
    if (!found)
      return false;
  }
  return true;
}

bool PetrickMethod::isCovered(char *minterm, char *prime) {
  for (int i = 0; i < variableSize; i++)
    if (prime[i] != 'x' && prime[i] != minterm[i])
      return false;
  return true;
}

void PetrickMethod::filterSolutions() {
  if (sumOfProducts.size == 0)
    return;

  int minSize = sumOfProducts.solution[0].size;
  for (int i = 1; i < sumOfProducts.size; i++)
    if (sumOfProducts.solution[i].size < minSize)
      minSize = sumOfProducts.solution[i].size;

  int newSize = 0;
  for (int i = 0; i < sumOfProducts.size; i++)
    if (sumOfProducts.solution[i].size == minSize)
      sumOfProducts.solution[newSize] = sumOfProducts.solution[i], newSize++;
  sumOfProducts.size = newSize;
}

void PetrickMethod::generateCombinations(int level, int *current, int count, bool implicantChart[16][16]) {
  if (level == onSet->size) {
    set_t tempSet;
    for (int i = 0; i < count; i++)
      strcpy(tempSet.terms[i], primeSet->terms[current[i]]), tempSet.size++;
    if (isSetInSolutions(tempSet))
      return;
    sumOfProducts.solution[sumOfProducts.size] = tempSet, sumOfProducts.size++;
    filterSolutions();
    return;
  }

  for (int i = 0; i < primeSet->size; i++) {
    if (!implicantChart[level][i])
      continue;
    if (Utils::isValueInArray(current, count, i)) {
      generateCombinations(level + 1, current, count, implicantChart);
      continue;
    }
    current[count] = i;
    generateCombinations(level + 1, current, count + 1, implicantChart);
  }
}