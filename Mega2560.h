/* Mega2560.h */
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define ON true
#define OFF false

#define turnOn(port, value) (port |= port | (ON << value))
#define turnOff(port, value) (port |= port & ~(ON << value))

// Digital ports
//dig2 [PORTE4, PINE4, DDRE]
//dig3 [PORTE5, PINE5, DDRE]
//dig4 [PORTG5, PING5, DDRG]
//dig5 [PORTE3, PINE3, DDRE]
//dig6 [PORTH3, PINH3, DDRH]
//dig7 [PORTH4, PINH4, DDRH]
//dig8 [PORTH5, PINH5, DDRH]
//dig9 [PORTH6, PINH6, DDRH]
//dig10 [PORTB4, PINB4, DDRB]

// serial port SIG_2WIRE_SERIAL
