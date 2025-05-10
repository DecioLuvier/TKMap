#ifndef Utils_h
#define Utils_h

namespace Utils {

bool isPowerOfTwo(int num);
bool isValueInArray(int *array, int size, int value);
bool isOdd(int num);
int decimalToGrayCode(int num);
void decimalToBinary(int number, char *output, int variableSize);

}

#endif