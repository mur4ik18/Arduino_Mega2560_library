/* Mega2560.h */
#include <stdbool.h>
#include <stdint.h>

#define ON true
#define OFF false

#define turnOn(port, value) (port |= port | (ON << value))
#define turnOff(port, value) (port |= port & ~(ON << value))

void digitalOutputMode(int8_t port);
void digitalWrite(int8_t port, bool value);
void bitsToArray(uint8_t num, uint8_t *bitters);
