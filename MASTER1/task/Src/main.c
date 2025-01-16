#include "stm32f401xx.h"
#include <stdio.h>

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

void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);


int main(void)
 {

    uart2_init_pins();
    uart2_init();

    while (1)
    {
        printf("%ld + %ld = %ld\n", *val1, *val2, *res);
        delay_cycles(16000000);
    }
}

void task1_handler(void)
{
    printf("This is task 1\n");
    while(1)
    {

    }
}

void task2_handler(void)
{
    printf("This is task 2\n");
    while(1)
    {

    }
}

void task3_handler(void)
{
    printf("This is task 3\n");
    while(1)
    {

    }
}

void task4_handler(void)
{
    printf("This is task 4\n");
    while(1)
    {

    }
}