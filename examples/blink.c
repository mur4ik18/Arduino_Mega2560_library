#include "../lib/Mega2560.h"
#include <util/delay.h>

// digital 13 - used for working with blink
#define LED 13

void setup() {
   pinMode(13, OUTPUT);
}

int main(void) {
    setup();
    while(1) {
        turn(LED, ON);
        _delay_ms(1000);
        turn(LED, OFF);
    }
    return 1;
}
