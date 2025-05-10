#include "Utils.h"

bool Utils::isPowerOfTwo(int num) {
  return num > 0 && (num & (num - 1)) == 0;
}

bool Utils::isOdd(int num) {
  return num % 2 != 0;
}

int Utils::decimalToGrayCode(int num) {
  return num ^ (num >> 1);
}

void Utils::decimalToBinary(int number, char *output, int variableSize) {
  for (int i = variableSize - 1; i >= 0; i--)
    if ((number >> i) & 1)
      output[variableSize - 1 - i] = '1';
    else
      output[variableSize - 1 - i] = '0';
  output[variableSize] = '\0';
}

bool Utils::isValueInArray(int *array, int arrSize, int value) {
  for (int i = 0; i < arrSize; i++)
    if (array[i] == value)
      return true;
  return false;
}