#include "./lib/UART_driver.h"
#include "./lib/Mega2560.h"
#include <util/delay.h>

int main(void) {
    USART_Init(MYUBRR);

    while (1) {
        _delay_ms(1000);
        print("Hello world\n");
    }
    return 1;
}

