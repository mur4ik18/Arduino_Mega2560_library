#include "../lib/Mega2560.h"
#include <util/delay.h>

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
        shiftOut(dataPin, clockPin, 0b10101011);
        turn(latchPin, ON);
        _delay_ms(1000);
    }
    return 1;
}
