#ifndef QuineMcCluskey_h
#define QuineMcCluskey_h

#include <string.h>
#include "../types.h"
#include "Utils.h"

// https://en.wikipedia.org/wiki/Quine%E2%80%93McCluskey_algorithm

struct buffer_t {
    char terms[32][5] = {};
    int size = 0;
};

class QuineMcCluskey {
  public:
    QuineMcCluskey(char *truthTable, int variableSize);
    set_t onSet;
    set_t primeSet;
  private:
    char *truthTable;
    int variableSize;
    int mintermToInt(char *minterm);
    bool isDashesAlign(char *minterm1, char *minterm2);
    bool isOneMintermDifference(char *minterm1, char *minterm2);
    bool isMintermInSet(char *minterm, buffer_t *set);
    void mergePrimeSet(char *minterm1, char *minterm2, char *output);
    void getPrimeImplicants(buffer_t *set);
};

#endif