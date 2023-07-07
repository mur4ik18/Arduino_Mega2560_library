#define __ATmegaxx0__
#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/iomxx0_1.h>
#include <avr/portpins.h>
#include "Mega2560.h"
#include <stdint.h>

#define F_CPU 16000000
#define FOSC 1843200
#define BAUD 9600
#define MYUBRR (FOSC/16/BAUD-1)
#include <util/setbaud.h>

void USART_Init(unsigned int ubrr);

int main(void) {
    USART_Init(MYUBRR);
    return 1;
}

void USART_Init(unsigned int ubrr) {
    /* Set baud rate */
    UBRRH = (unsigned char) (ubrr >> 8);
    UBRRL = (unsigned char) ubrr;

    /* Enable receiver and transmitter */
    UCSRB = (1 << RXEN) | (1<<TXEN);

    /* Set frame format: 8data, 2stop bit */
    UCSRC = (1<<USBS) | (3<<UCSZ0);
}
