#include "StateUtils.h"

void StateUtils::formatPrimeSet(int variableSize, set_t *studentPrimeSet, char *buffer, bool showDontCare) {
  const char variables[] = "ABCD";
  for (int i = 0; i < studentPrimeSet->size; i++) {
    for (int j = 0; j < variableSize; j++) {
      if (studentPrimeSet->terms[i][j] == 'x') {
        if (showDontCare)
          strncat(buffer, "x", 1);
        continue;
      }
      strncat(buffer, &variables[j], 1);
      if (studentPrimeSet->terms[i][j] == '0')
        strncat(buffer, "'", 1);
    }

    if (i < studentPrimeSet->size - 1) {
      strcat(buffer, " +");
      if (Utils::isOdd(i))
        strcat(buffer, "\n");
      else
        strcat(buffer, " ");
    }
  }
}

void StateUtils::indexToChar(char source, char *target) {
  if (source == '0')
    strcat(target, "False");
  else if (source == '1')
    strcat(target, "True");
  else
    strcat(target, "Don't care");
}

void StateUtils::toggleTruthTableValue(char *value) {
  if (*value == '0')
    *value = '1';
  else if (*value == '1')
    *value = 'x';
  else
    *value = '0';
}

void StateUtils::wrapIndexInRange(int *index, int delta, int min, int max) {
  int value = *index + delta;
  if (value > max)
    value = min + (value - max - 1) % (max - min + 1);
  else if (value < min)
    value = max - (min - value - 1) % (max - min + 1);
  *index = value;
}