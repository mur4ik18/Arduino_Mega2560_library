#include "lib_74HC595.h"
#include "Mega2560.h"

#include <stdint.h>
#include <stdio.h>

void shiftOut(int8_t dataPin, int8_t clockPin, uint8_t data) {
    for(int8_t i = 0; i < 8; i++) {
        if ((data & 128) != 0 ) {
            turn(dataPin, ON);
        } else {
            turn(dataPin, OFF);
        }
        data = data << 1;
        turn(clockPin, ON);
        turn(clockPin, OFF);
    }
}
