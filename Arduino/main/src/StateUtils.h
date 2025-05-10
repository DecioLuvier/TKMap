#ifndef StateUtils_h
#define StateUtils_h

#include <Arduino.h>
#include "types.h"
#include "libs/Utils.h"

namespace StateUtils {

void formatPrimeSet(int variableSize, set_t *studentPrimeSet, char *buffer, bool showDontCare);
void indexToChar(char source, char *target);
void toggleTruthTableValue(char *value);
void wrapIndexInRange(int *index, int delta, int min, int max);

}

#endif