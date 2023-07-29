#include "Mega2560.h"

void setNumber(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t figure) {
    turn(latchPin, OFF);
    //shiftOut(dataPin, clockPin, digitToByte + figure);
    shiftOut(dataPin, clockPin, digitToByte[figure]);
    turn(latchPin, ON);
}

void setByte(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t byte) {
    turn(latchPin, OFF);
    //shiftOut(dataPin, clockPin, digitToByte + figure);
    shiftOut(dataPin, clockPin, byte);
    turn(latchPin, ON);
}
