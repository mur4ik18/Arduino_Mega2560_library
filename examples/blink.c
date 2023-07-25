#include "../lib/Mega2560.h"
#include <util/delay.h>

// digital 13 - used for working with blink
const LED = 13;

void setup() {
   pinMode(13, OUTPUT);
}

uint8_t main(void) {
    setup();
    while(1) {
        turnOn(LED);
        _delay_ms(1000);
        turnOff(LED);
    }
    return 1;
}
