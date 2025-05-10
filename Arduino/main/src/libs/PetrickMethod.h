#ifndef PetrickMethod_h
#define PetrickMethod_h

#include <string.h>
#include "../types.h"
#include "Utils.h"

// https://en.wikipedia.org/wiki/Petrick%27s_method
// https://medium.com/mirkat-x-blog/implement-quine-mccluskey-algorithm-and-petricks-method-in-c-40168163474

struct solutions_t {
    set_t solution[16] = {};
    int size = 0;
};

class PetrickMethod {
  public:
    PetrickMethod(set_t *onSet, set_t *primeSet, int variableSize);
    solutions_t sumOfProducts;
    bool isSetInSolutions(set_t &set);
    bool isSetEquivalent(set_t &setA, set_t &setB);
  private:
    set_t *onSet;
    set_t *primeSet;
    int variableSize;
    void filterSolutions();
    void generateCombinations(int level, int *current, int count, bool implicantChart[16][16]);
    bool isCovered(char *minterm, char *prime);
};

#endif