#include "../lib/Mega2560.h"
#include <util/delay.h>

// ------- 74HC595 Pinout -------
//  Q0      = 15
//  Q1-Q7   = 1-7
//  GND     = 8
//  Vcc     = 16 (5V)
//  Q0      = 15
//  Ds      = 14 (dataPin)
//  OE      = 13
//  STcp    = 12 (latchPin)
//  SHcp    = 11 (clockPin)
//  MR      = 10
// ------------------------------
const uint8_t dataPin = 2;
const uint8_t latchPin = 3;
const uint8_t clockPin = 4;

void setup() {
    USART_Init(MYUBRR);
    print("Started");

    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
}

int main(void) {
    setup();
    while (1) {
        turn(latchPin, OFF);
        shiftOut(dataPin, clockPin, 0b01111111);
        turn(latchPin, ON);
        _delay_ms(1000);
    }
    return 1;
}
