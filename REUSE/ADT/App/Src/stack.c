#include "stack.h"
#include <stdio.h>



stack* stack_create(void)
{
    printf("Stack created\n\r");
    return NULL;
}

void stack_destroy(stack *s)
{
    printf("Stack destroyed\n\r");
}