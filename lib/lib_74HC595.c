#include "lib_74HC595.h"
#include "Mega2560.h"
#include "print.h"

#include <stdint.h>
#include <stdio.h>

void shiftOut(int8_t dataPin, int8_t clockPin, uint8_t data) {
    for(int8_t i = 0; i < 8; i++) {
        digitalWrite(dataPin, data & 1);
        data <<= 1;
        digitalWrite(clockPin, ON);
        digitalWrite(clockPin, OFF);
    }
}
