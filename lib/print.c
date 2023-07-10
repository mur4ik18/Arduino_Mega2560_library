#include "print.h"
#include "UART_driver.h"

#include <stdint.h>
#include <string.h>

void print(char * data) {
    int16_t len = strlen(data);
    for (int16_t i = 0; i < len; i++) {
        USART_Transmit((int)data[i]);
    }

}
