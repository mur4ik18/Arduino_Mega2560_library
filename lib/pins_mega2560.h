#ifndef PINS_MEGA2560_H
#define PINS_MEGA2560_H

#define __ATmegaxx0__

#include "Mega2560.h"
#include "avr/pgmspace.h"
#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/iomxx0_1.h>
#include <avr/portpins.h>
#include <stdint.h>

#define PA 0
#define PB 1
#define PC 2
#define PD 3
#define PE 4
#define PF 5
#define PG 6
#define PH 7
#define PJ 8
#define PK 9
#define PL 10

void pinMode(uint8_t pin, uint8_t mode);

// registers - DDRA-DDRL
const uint16_t ddrx[] = {
    (uint16_t) &DDRA,
    (uint16_t) &DDRB,
    (uint16_t) &DDRC,
    (uint16_t) &DDRD,
    (uint16_t) &DDRE,
    (uint16_t) &DDRF,
    (uint16_t) &DDRG,
    (uint16_t) &DDRH,
    (uint16_t) &DDRJ,
    (uint16_t) &DDRK,
    (uint16_t) &DDRL,
}; 

// ports - PORTA-PORTL
const uint16_t portx[] = {
    (uint16_t) &PORTA,
    (uint16_t) &PORTB,
    (uint16_t) &PORTC,
    (uint16_t) &PORTD,
    (uint16_t) &PORTE,
    (uint16_t) &PORTF,
    (uint16_t) &PORTG,
    (uint16_t) &PORTH,
    (uint16_t) &PORTJ,
    (uint16_t) &PORTK,
    (uint16_t) &PORTL,
}; 

// pins - PINA-PINL
const uint16_t pinx[] = {
    (uint16_t) &PINA,
    (uint16_t) &PINB,
    (uint16_t) &PINC,
    (uint16_t) &PIND,
    (uint16_t) &PINE,
    (uint16_t) &PINF,
    (uint16_t) &PING,
    (uint16_t) &PINH,
    (uint16_t) &PINJ,
    (uint16_t) &PINK,
    (uint16_t) &PINL,
}; 

const uint8_t digital_pin_masks[] = {
	_BV( 0 ), // d0 PE 0 - USART0_RX
	_BV( 1 ), // d1 PE 1 - USART0_TX	
	_BV( 4 ), // d2 PE 4
    _BV( 5 ), // d3 PE 5
	_BV( 5 ), // d4 PG 5
	_BV( 3 ), // d5 PE 3
	_BV( 3 ), // d6 PH 3 
	_BV( 4 ), // d7 PH 4 
	_BV( 5 ), // d8 PH 5
	_BV( 6 ), // d9 PH 6
	_BV( 4 ), // d10 PB 4
	_BV( 5 ), // d11 PB 5
	_BV( 6 ), // d12 PB 6
	_BV( 7 ), // d13 PB 7
};


// it is ports 
const uint8_t digital_ports[] = {
	PE, // d0 PE 0 - USART0_RX	
	PE, // d1 PE 1 - USART0_TX	
	PE, // d2 PE 4
	PE, // d3 PE 5
	PG, // d4 PG 5
	PE, // d5 PE 3
	PH, // d6 PH 3
	PH, // d7 PH 4
	PH, // d8 PH 5
	PH, // d9 PH 6
	PB, // d10 PB 4
	PB, // d11 PB 5
	PB, // d12 PB 6	
	PB, // d13 PB 7	
};

#endif
