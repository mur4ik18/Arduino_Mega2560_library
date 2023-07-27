#include "../lib/Mega2560.h"
#include <util/delay.h>

// digital 13 - used for working with blink
#define LED 13

void setup() {
    pinMode(13, OUTPUT);
    USART_Init(MYUBRR);
    USART_Transmit("Started");
}

int main(void) {
    setup();
    while(1) {
        turn(LED, ON);
        print("LED On\n");
        _delay_ms(1000);
        turn(LED, OFF);
        print("LED OFF\n");
        _delay_ms(1000);
    }
    return 1;
}
