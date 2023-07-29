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
        // show all figures
        uint8_t i = 0;
        for (i; i<=9; i++) {
            setNumber(dataPin, clockPin, latchPin, i);  
            print(i);
            _delay_ms(1000);
        }

        // show infinity
        while (1) {
           setByte(dataPin, clockPin, latchPin, 0b00000001); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b00000011); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b10000010); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b10100000); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b00110000); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b00010100); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b10000100); 
            _delay_ms(50);
           setByte(dataPin, clockPin, latchPin, 0b11000000); 
            _delay_ms(50);
        }
    }
    return 1;
}
