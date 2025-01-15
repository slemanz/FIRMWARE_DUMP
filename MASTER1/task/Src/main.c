#include "stm32f401xx.h"
#include <stdio.h>

/*
    Exemple: Load 2 values from memory, add them and store the result back to 
    the memory using inline assembly statements.
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

    int32_t *val1 = (int32_t *)0x20001000L;
    int32_t *val2 = (int32_t *)0x20001004L;
    int32_t *res =  (int32_t *)0x20001008L;

    *val1 = 12;
    *val2 = 8;
    *res  = 0;

    __asm volatile("LDR R1, =#0x20001000");
    __asm volatile("LDR R2, =#0x20001004");
    __asm volatile("LDR R3, =#0x20001008");
    __asm volatile("LDR R0, [R1]");
    __asm volatile("LDR R1, [R2]");
    __asm volatile("ADD R0, R0, R1");
    __asm volatile("STR R0, [R3]");

    while (1)
    {
        printf("%ld + %ld = %ld\n", *val1, *val2, *res);
        delay_cycles(16000000);
    }
}