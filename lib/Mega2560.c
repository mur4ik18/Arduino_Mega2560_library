#define __ATmegaxx0__
#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/iomxx0_1.h>
#include <avr/portpins.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "Mega2560.h"

void turn(uint8_t port, bool onoff) {
    volatile uint8_t *out = getPort(digital_to_port(port));
    volatile uint8_t bit = getBit(port);
    if (onoff == ON) {
        *out |= bit;
    } else {
        *out &= ~bit;
    }
}

void pinMode(uint8_t num, bool mode) {
    uint8_t port = digital_to_port(num);
    uint8_t bit = getBit(num);
    volatile uint8_t *reg, *pin;
    reg = getReg(port);
    pin = getPin(port);

    if (mode == INPUT) {
        uint8_t saved_SREG = SREG;
        *reg &= ~bit;
        *pin &= ~bit;
        SREG = saved_SREG;
    } else {
        uint8_t saved_SREG = SREG;
        *reg |= bit;
        SREG = saved_SREG;
    }

}
