#include "Mega2560.h"

#include "avr/pgmspace.h"
#include "pins_mega2560.h"

void pinMode(uint8_t num, uint8_t mode) {
    uint8_t port = digital_to_port(num);
    uint8_t bit = getBit(num);
    volatile uint8_t *reg, *pin;
    reg = getReg(port);
    pin = getPin(port);

    if (mode == INPUT) {
        uint8_t saved_SREG = SREG;
        cli();
        *reg &= ~bit;
        *pin &= ~bit;
        SREG = saved_SREG;
    } else {
        uint8_t saved_SREG = SREG;
        cli();
        *reg |= bit;
        SREG = saved_SREG;
    }

}
