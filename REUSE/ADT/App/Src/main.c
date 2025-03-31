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

    stack_push(s1, 12);
    stack_push(s1, 13);
    stack_push(s1, 14);

    printf("Stack item: %ld\n\r", stack_peek(s1));

    printf("==========\n\r");
    printf("Stack item: %ld\n\r", stack_pop(s1));
    printf("Stack item: %ld\n\r", stack_pop(s1));
    printf("Stack item: %ld\n\r", stack_pop(s1));

    stack_destroy(s1);

    while (1)
    {
    }
}