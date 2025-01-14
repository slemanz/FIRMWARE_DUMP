#include "stm32f401xx.h"
#include <stdio.h>

/*
    SVC Exemple: 
    A program to execute a SVC instruction from thread mode,
    implementing the SVC handler to print the SVC number used. Also,
    incrementing the SVC number by 4 and returning it to the thread mode
    code and printint it.
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
    while (cycles-- > 0) __asm("NOP"); // No operation for delay
}

int main(void)
 {

    uart2_init_pins();
    uart2_init();

    __asm("SVC #8");

    while (1)
    {
        delay_cycles(16000000);
    }
}

__attribute__((naked)) void SVC_Handler(void)
{
    // 1. get the value of the MSP
    __asm("MRS R0, MSP"); // first argument
    __asm("B SVC_Handler_c");
}

void SVC_Handler_c(uint32_t *pBaseOfStackFrame)
{
    printf("In SVC handler\n");

    uint8_t *pReturn_addr = (uint8_t*)pBaseOfStackFrame[6];

    // 2. decrement the return address by 2 to point to
    // opcode of the SVC instruction in the program memory
    pReturn_addr -= 2;

    // 3. extract the SVC number (LSB byte of opcode)
    uint8_t svc_number = *pReturn_addr;
    printf("SVC number is: %d\n", svc_number);
}