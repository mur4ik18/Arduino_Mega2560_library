#ifndef LIB_74HC595_H
#define LIB_74HC595_H

#include <stdint.h>

void prepareSending(int8_t latchPin, int8_t resetPin, int8_t outputEnablePin);
void shiftOut(int8_t dataPin, int8_t clockPin, uint8_t data);
void endSending(int8_t latchPin, int8_t resetPin, int8_t outputEnablePin);

#endif
