#include "UART_driver.h"

void USART_Init(unsigned char ubrr) {
    /* Set baud rate */
    UBRR0H = (unsigned char) (ubrr >> 8);
    UBRR0L = (unsigned char) ubrr;

    /* Enable receiver and transmitter */
    UCSR0B = (1 << RXEN0) | (1<<TXEN0);

    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0) | (3<<UCSZ00);
}

void USART_Transmit( int8_t data) {
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );

    /* Put data into buffer, sends the data */  
    UDR0 = data;
}

unsigned char USART_Recive(void) {
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) );

    /* Get and return received data from buffer */  
    return UDR0;
}

void print(char * data) {
    int16_t len = strlen(data);
    for (int16_t i = 0; i < len; i++) {
        USART_Transmit((int)data[i]);
    }

}
