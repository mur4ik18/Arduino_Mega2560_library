#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "Mega2560.h"
#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/iomxx0_1.h>
#include <avr/portpins.h>
#include <util/delay.h>


#define F_CPU 16000000
#define BAUD 9600
#define MYUBRR (F_CPU/16/BAUD-1)
#include <util/setbaud.h>


void USART_Init(unsigned char ubrr);
void USART_Transmit( int8_t data);
unsigned char USART_Recive(void);
void print(char * data);




#endif /* UART_DRIVER_H */
