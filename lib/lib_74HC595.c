#include "lib_74HC595.h"
#include "Mega2560.h"

#include <stdint.h>


void prepareSending(int8_t latchPin, int8_t resetPin, int8_t outputEnablePin) {
    digitalWrite(latchPin, OFF);
    digitalWrite(resetPin, ON);
    digitalWrite(outputEnablePin, OFF);
}

void shiftOut(int8_t dataPin, int8_t clockPin, uint8_t data) {
    uint8_t bittsArray[7] = {0,0,0,0,0,0,0};
    bitsToArray(data, bittsArray);

    for(int8_t i = 0; i <= 8; i++) {
        true ? digitalWrite(dataPin, ON): digitalWrite(dataPin, OFF);
        digitalWrite(clockPin, ON);
        digitalWrite(clockPin, OFF);
    }

}

void endSending(int8_t latchPin, int8_t resetPin, int8_t outputEnablePin) {
    // start sending
    digitalWrite(latchPin, ON);
    digitalWrite(outputEnablePin, ON);
}
