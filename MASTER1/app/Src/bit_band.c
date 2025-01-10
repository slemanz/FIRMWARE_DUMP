#include "stm32f401xx.h"
#include <stdio.h>

/*
    Exemple: Modify the content of the memory location 0x2000 0200 using usual and
    bit banding method and analyze the difference.
    - First store the value 0xFF in the memory location 0x2000 0200
    - Make the 7th-bit position of the value to 0

    Calculation of bit band alias address
    General formula: 
    alias address = alias_base+(32*(bit_band_memory_addr - bit_band_base)) + bit*4
    alias address = 0x2200 0000 + (32*(0x2000 0200 - 0x2000 0000)) + 7*4

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

#define ALIAS_BASE      0x22000000U
#define BITBAND_BASE    0x20000000U

int main(void)
 {

    uart2_init_pins();
    uart2_init();

    uint8_t *ptr = (uint8_t*)0x20000200;

    // normal method
    // clearing 7th-bit position
    *ptr = 0xff;
    *ptr &= ~(1 << 7);

    // bit band method
    // clearing 7th-bit position of address 0x20000200
    *ptr = 0xff;
    uint8_t *alias_addr = (uint8_t*)(ALIAS_BASE+(32*(0x20000200-BITBAND_BASE)) + 7*4);
    *alias_addr = 0;


    while (1)
    {
        delay_cycles(16000000);
    }
}