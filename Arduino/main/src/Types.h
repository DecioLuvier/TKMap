#ifndef Types_h
#define Types_h

#include <Arduino.h>

struct set_t {
    char terms[16][5] = {};
    uint8_t size = 0;
};

#endif