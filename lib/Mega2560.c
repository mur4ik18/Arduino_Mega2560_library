#define __ATmegaxx0__
#include <avr/io.h>
#include <avr/iom2560.h>
#include <avr/iomxx0_1.h>
#include <avr/portpins.h>

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "Mega2560.h"
#include "UART_driver.h"


void digitalOutputMode(int8_t port);
void digitalWrite(int8_t port, bool value);
void bitsToArray(uint8_t num, uint8_t *bitters);

void digitalOutputMode(int8_t port) {
    switch (port) {
        case 2:
            DDRE |= (1 << 4);
            break;
        case 3:
            DDRE |= (1 << 5);
            break;
        case 4:
            DDRG |= (1 << 5);
            break;
        case 5:
            DDRE |= (1 << 3);
            break;
        case 6:
            DDRH |= (1 << 3);
            break;
        case 7:
            DDRH |= (1 << 4);
            break;
        case 8:
            DDRH |= (1 << 5);
            break;
        case 9:
            DDRH |= (1 << 6);
            break;
        case 10:
            DDRB |= (1 << 4);
        default:
            break;
    }
}

void digitalWrite(int8_t port, bool value) {
    switch (port) {
        case 2:
            value? turnOn(PORTE, PE4) : turnOff(PORTE, PE4);
            break;
        case 3:
            value? turnOn(PORTE, PE5) : turnOff(PORTE, PE5);
            break;
        case 4:
            value? turnOn(PORTG, PG5) : turnOff(PORTG, PG5);
            break;
        case 5:
            value? turnOn(PORTE, PE3) : turnOff(PORTE, PE3);
            break;
        case 6:
            value? turnOn(PORTH, PH3) : turnOff(PORTH, PH3);
            break;
        case 7:
            value? turnOn(PORTH, PH4) : turnOff(PORTH, PH4);
            break;
        case 8:
            value? turnOn(PORTH, PH5) : turnOff(PORTH, PH5);
            break;
        case 9:
            value? turnOn(PORTH, PH6) : turnOff(PORTH, PH6);
            break;
        case 10:
            value? turnOn(PORTB, PB4) : turnOff(PORTB, PB4);
        default:
            break;
    }
}



void bitsToArray(uint8_t num, uint8_t *bitters){
    unsigned int size = sizeof(unsigned char);
    unsigned int maxPow = 1<<(size*8-1);
    int bittsArray[7] = {0,0,0,0,0,0,0};
    int i=0,j;
    for(;i<size;++i){
        for(j=0;j<8;++j){
            for(;i<size*8;++i){
                bittsArray[i] = num&maxPow ? 1 : 0;
                num = num<<1;
            }
        }
    }
    int k = 0;
    for (int i=7; i>=0;i--) {
        bitters[k++] = bittsArray[i];
    } 
}
