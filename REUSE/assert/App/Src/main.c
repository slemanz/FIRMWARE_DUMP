#include "stm32f401xx.h"
#include <stdio.h>
#include "common-defines.h" // ASSERT is defined here, the assert failed is in syscalls
#include "system.h"
#include <stdbool.h>


uint32_t func_sum(uint32_t a, uint32_t b)
{
    ASSERT(a); // just to test assert
    ASSERT(b);
    return a + b;
}


int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    ASSERT(1); // ok

    uint32_t temp_a = 0;
    uint32_t temp_b = 20;

    uint32_t sum = func_sum(temp_a, temp_b);
    printf("Sum: %ld + %ld = %ld\n\r", temp_a, temp_b, sum);

    while (1)
    {
    }
}
