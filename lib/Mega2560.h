/* Mega2560.h */
#include <stdbool.h>
#include <stdint.h>
#include <avr/pgmspace.h>
#include "pins_mega2560.h"

#define ON true
#define OFF false
#define INPUT 2
#define OUTPUT 3

// Here you should use number of digital port.
#define digital_to_port(x) (pgm_read_byte( digital_ports + x ))
#define getBit(x) (pgm_read_byte( digital_pin_masks + x ))
// for getting Register and Pin you should use digital_to_port. 
#define getReg(x) ((volatile uint8_t *) pgm_read_byte( ddrx + x ))
#define getPin(x) ((volatile uint8_t *) pgm_read_byte( pinx + x ))
// For getting Port you can use digital_to_port.
#define getPort(x) (pgm_read_byte( portx + x ))

#define turnOn(port) ( getPort(digital_to_port(port)) |= getPort(digital_to_port(port)) | (ON << getBit(port) ))
#define turnOff(port) ( getPort(digital_to_port(port)) |= getPort(digital_to_port(port)) & ~(ON << getBit(port) ))

void bitsToArray(uint8_t num, uint8_t *bitters);
