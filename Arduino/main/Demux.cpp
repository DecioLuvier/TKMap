#include "Demux.h"

void Demux::begin() {
  pinMode(OUTPUT_MATRIX_X, INPUT);
  pinMode(BUTTON_ROW_A, OUTPUT);
  pinMode(BUTTON_ROW_B, OUTPUT);
  pinMode(BUTTON_ROW_C, OUTPUT);
  pinMode(BUTTON_ROW_D, OUTPUT);
  pinMode(BUTTON_COL_A, OUTPUT);
  pinMode(BUTTON_COL_B, OUTPUT);
  pinMode(BUTTON_COL_C, OUTPUT);
  pinMode(BUTTON_COL_D, OUTPUT);
}

bool Demux::readValue(byte value) {
  digitalWrite(BUTTON_ROW_A, (value >> 0) & 1);
  digitalWrite(BUTTON_ROW_B, (value >> 1) & 1);
  digitalWrite(BUTTON_ROW_C, (value >> 2) & 1);
  digitalWrite(BUTTON_ROW_D, (value >> 3) & 1);
  digitalWrite(BUTTON_COL_A, (value >> 4) & 1);
  digitalWrite(BUTTON_COL_B, (value >> 5) & 1);
  digitalWrite(BUTTON_COL_C, (value >> 6) & 1);
  digitalWrite(BUTTON_COL_D, (value >> 7) & 1);
  return digitalRead(OUTPUT_MATRIX_X);
}

void Demux::readMatrix(const byte *map, byte size, bool *output) {
  for (byte i = 0; i < size; i++)
    output[i] = readValue(map[i]);
}