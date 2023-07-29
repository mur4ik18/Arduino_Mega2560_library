#ifndef DIG_7SEG_DISPLAY_H
#define DIG_7SEG_DISPLAY_H
#include <stdint.h>

//    gfed.cba
//  0b10101010
static const uint8_t digitToByte[] = {
    0b01110111,     // 0
    0b00000110,     // 1
    0b10110011,     // 2
    0b10010111,     // 3
    0b11000110,     // 4
    0b11010101,     // 5
    0b11110101,     // 6
    0b00000111,     // 7
    0b11110111,     // 8
    0b11010111,     // 9
};

void setNumber(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t figure);
void setByte(uint8_t dataPin, uint8_t clockPin, uint8_t latchPin, uint8_t byte);

#endif /* DIG_7SEG_DISPLAY_H */
