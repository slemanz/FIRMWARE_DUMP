#include "stm32f401xx.h"
#include <stdio.h>
#include "common-defines.h" 
#include "system.h"

float cb_square(int num)
{
    return num*num;
}

float cb_cube(int num)
{
    return num*num*num;
}

typedef float (*op_t)(int);

float calc(int num, op_t op)
{
    return op(num);
}

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    printf("2^2 = %.1f\n\r", calc(2, cb_square));
    printf("2^3 = %.1f\n\r", calc(2, cb_cube));


    while (1)
    {
    }
}
