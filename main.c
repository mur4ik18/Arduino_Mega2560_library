#include "UART_driver.h"

int main(void) {
    USART_Init(MYUBRR);

    while (true) {
        _delay_ms(1000);
        // USART_Transmit(0x41); //USART_sendChar(0x41);
        print("Hello world\n");
    }
    return 1;
}

