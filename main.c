#include "./lib/UART_driver.h"
#include "./lib/Mega2560.h"
#include <util/delay.h>

#define DEBUG 1

#define F_CPU 16000000UL //16MHz

//  dataPin - 14 (74hc959)
//  latchPin - 12 (74hc959)
//  clockPin - 11 (74hc959)

// digital 5 - 13 (74hc959)
// digital 6 - 10 (75hc959)

const int8_t dataPin = 2; 
const int8_t latchPin = 3;
const int8_t clockPin = 4;
// const int outputEnablePin = 5;
// const int resetPin = 6;

void setup() {
//    digitalOutputMode(dataPin);
//    digitalOutputMode(latchPin);
//    digitalOutputMode(clockPin);

    USART_Init(MYUBRR);
};

int main(void) {
    setup();
    
    while (1) {
        // digitalWrite(outputEnablePin, OFF);
        // digitalWrite(resetPin, ON);

        _delay_ms(1000);
    }
    return 1;
}
