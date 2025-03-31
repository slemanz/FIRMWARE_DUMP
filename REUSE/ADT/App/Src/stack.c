#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_create(void)
{
    stack *s = (stack*)malloc(sizeof(stack));

    if(!s)
    {
        printf("Not able to create stack.\n\r");
        return NULL;
    }

    printf("Stack created\n\r");
    return s;
}

void stack_destroy(stack *s)
{
    free(s);
    printf("Stack destroyed\n\r");
}