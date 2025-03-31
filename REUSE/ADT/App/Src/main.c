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
    if(s1 == NULL)
    {
        printf("Error\n\r");
        while(1);
    }

    stack_destroy(s1);

    while (1)
    {
    }
}