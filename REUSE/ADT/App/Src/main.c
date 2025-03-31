#include "stm32f401xx.h"
#include <stdio.h>
#include "system.h"

#include "stack.h"


int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    stack *s1 = stack_create();

    stack_destroy(s1);

    while (1)
    {
    }
}