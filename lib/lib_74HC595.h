#ifndef LIB_74HC595_H
#define LIB_74HC595_H

#include <stdint.h>

void shiftOut(int8_t dataPin, int8_t clockPin, uint8_t data);

#endif
