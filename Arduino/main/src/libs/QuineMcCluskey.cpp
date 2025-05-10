#include "QuineMcCluskey.h"

QuineMcCluskey::QuineMcCluskey(char *truthTable, int variableSize) : truthTable(truthTable), variableSize(variableSize) {
  buffer_t primeSetBuffer;
  for (int i = 0; i < (1 << variableSize); i++) {
    if (truthTable[i] == '1' || truthTable[i] == 'x')
      Utils::decimalToBinary(i, primeSetBuffer.terms[primeSetBuffer.size], variableSize), primeSetBuffer.size++;
    if (truthTable[i] == '1')
      Utils::decimalToBinary(i, onSet.terms[onSet.size], variableSize), onSet.size++;
  }

  getPrimeImplicants(&primeSetBuffer);
  for (int i = 0; i < primeSetBuffer.size; i++)
    strcpy(primeSet.terms[i], primeSetBuffer.terms[i]);
  primeSet.size = primeSetBuffer.size;
}

void QuineMcCluskey::mergePrimeSet(char *minterm1, char *minterm2, char *output) {
  for (int i = 0; i < variableSize; i++)
    if (minterm1[i] != minterm2[i])
      output[i] = 'x';
    else
      output[i] = minterm1[i];
  output[variableSize] = '\0';
}

int QuineMcCluskey::mintermToInt(char *minterm) {
  int result = 0;
  for (int i = 0; i < variableSize; i++) {
    result <<= 1;
    if (minterm[i] == '1')
      result |= 1;
  }
  return result;
}

bool QuineMcCluskey::isDashesAlign(char *minterm1, char *minterm2) {
  for (int i = 0; i < variableSize; i++)
    if (minterm1[i] != 'x' && minterm2[i] == 'x')
      return false;
  return true;
}

bool QuineMcCluskey::isOneMintermDifference(char *minterm1, char *minterm2) {
  int m1 = mintermToInt(minterm1);
  int m2 = mintermToInt(minterm2);
  int res = m1 ^ m2;
  return (res != 0) && ((res & (res - 1)) == 0);
}

bool QuineMcCluskey::isMintermInSet(char *minterm, buffer_t *set) {
  for (int i = 0; i < set->size; i++)
    if (strcmp(minterm, set->terms[i]) == 0)
      return true;
  return false;
}

void QuineMcCluskey::getPrimeImplicants(buffer_t *set) {
  buffer_t tempSet;
  bool merges[32] = {false};
  bool hasMerged = false;

  for (int i = 0; i < set->size; i++) {
    for (int j = i + 1; j < set->size; j++) {
      if (!isDashesAlign(set->terms[i], set->terms[j]) || !isOneMintermDifference(set->terms[i], set->terms[j]))
        continue;
      char mergedMinterm[5] = {0};
      mergePrimeSet(set->terms[i], set->terms[j], mergedMinterm);
      if (!isMintermInSet(mergedMinterm, &tempSet))
        strcpy(tempSet.terms[tempSet.size], mergedMinterm), tempSet.size++;
      hasMerged = true;
      merges[i] = true;
      merges[j] = true;
    }
  }

  for (int i = 0; i < set->size; i++)
    if (!merges[i] && !isMintermInSet(set->terms[i], &tempSet))
      strcpy(tempSet.terms[tempSet.size], set->terms[i]), tempSet.size++;

  if (!hasMerged)
    return;

  for (int i = 0; i < tempSet.size; i++)
    strcpy(set->terms[i], tempSet.terms[i]);
  set->size = tempSet.size;

  getPrimeImplicants(set);
}
