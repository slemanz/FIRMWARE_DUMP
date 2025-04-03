#include "stm32f401xx.h"
#include <stdio.h>
#include "common-defines.h" // ASSERT is defined here, the assert failed is in syscalls
#include "system.h"
#include <stdbool.h>

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");


    while (1)
    {
    }
}
