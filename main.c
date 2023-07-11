#include "./lib/UART_driver.h"
#include "./lib/Mega2560.h"
#include <util/delay.h>
#include "./lib/lib_74HC595.h"

#define DEBUG 1

#define F_CPU 16000000UL //16MHz

// digital 2 - 14 (74hc959)
// digital 3 - 11 (74hc959)
// digital 4 - 12 (74hc959)
// digital 5 - 13 (74hc959)
// digital 6 - 10 (75hc959)

const int dataPin = 2; 
const int latchPin = 3;
const int clockPin = 4;
const int outputEnablePin = 5;
const int resetPin = 6;

void setup() {
    digitalOutputMode(dataPin);
    digitalOutputMode(latchPin);
    digitalOutputMode(clockPin);
    digitalOutputMode(outputEnablePin);
    digitalOutputMode(resetPin);

    USART_Init(MYUBRR);
}

int main(void) {
    setup();
    print("Hello world\n");
    while (1) {
        _delay_ms(1000);
        prepareSending(latchPin, resetPin, outputEnablePin);
        print("prepared\n");
        shiftOut(dataPin, clockPin, 0b01010101);
        print("sended\n");
        endSending(latchPin, resetPin, outputEnablePin);
        print("closed\n");
    }
    return 1;
}

