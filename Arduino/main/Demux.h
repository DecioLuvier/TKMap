#ifndef Demux_h
#define Demux_h

#include <Arduino.h>

#define BUTTON_ROW_A 6
#define BUTTON_ROW_B 7
#define BUTTON_ROW_C 8
#define BUTTON_ROW_D 9
#define BUTTON_COL_A 10
#define BUTTON_COL_B 11
#define BUTTON_COL_C 12
#define BUTTON_COL_D 13
#define OUTPUT_MATRIX_X A0

static const uint8_t sizeBorders = 40;
static const uint8_t sizeTruthTable = 16;
const uint8_t mapBorders[sizeBorders] = {1,  3,  5,  7,  16, 18, 20, 22, 24, 33,  35,  37,  39,  48,  50,  52,  54,  56,  65,  67,
                                         69, 71, 80, 82, 84, 86, 88, 97, 99, 101, 103, 112, 114, 116, 118, 120, 129, 131, 133, 135};
const uint8_t mapTrue[sizeTruthTable] = {17, 19, 21, 23, 49, 51, 53, 55, 81, 83, 85, 87, 113, 115, 117, 119};
const uint8_t mapDontCare[sizeTruthTable] = {2, 4, 6, 8, 34, 36, 38, 40, 66, 68, 70, 72, 98, 100, 102, 104};

class Demux {
  public:
    void begin();
    bool readValue(uint8_t value);
    void readMatrix(const uint8_t *map, uint8_t size, bool *output);
};

#endif