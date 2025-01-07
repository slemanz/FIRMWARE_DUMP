#include "stm32f401xx.h"
#include <stdio.h>

/*
    Exemple: 
 */

void uart2_init_pins(void);

extern int __io_putchar(int ch)
{
    uart2_write_byte((uint8_t)ch);
    return ch;

}

// Function delay
void delay_cycles(uint32_t cycles)
{
    while (cycles-- > 0) {
        __asm("NOP"); // No operation for delay
    }
}

int main(void)
 {

    uart2_init_pins();
    uart2_init();


    while (1)
    {
        delay_cycles(16000000);
    }
}