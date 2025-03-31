#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct mys{
    uint32_t items[STACK_MAX_SIZE];
    int top;
} stack;

stack* stack_create(void)
{
    stack *s = (stack*)malloc(sizeof(stack));

    if(!s)
    {
        printf("Not able to create stack.\n\r");
        return NULL;
    }

    s->top = -1;

    printf("Stack created\n\r");
    return s;
}

void stack_destroy(stack *s)
{
    free(s);
    printf("Stack destroyed\n\r");
}

bool stack_isFull(stack *s)
{
    return (s->top == (STACK_MAX_SIZE - 1));
}

bool stack_isEmpty(stack *s)
{
    return (s->top == -1);
}

bool stack_push(stack *s, uint32_t item)
{
    if(stack_isFull(s))
    {
        return false;
    }

    s->top = (s->top+1);
    s->items[s->top] = item;
    return true;
}

uint32_t stack_pop(stack *s)
{
    uint32_t temp = 0;
    if(stack_isEmpty(s))
    {
        return temp;
    }
    
    temp = s->items[s->top];
    s->top = (s->top - 1);

    return temp;
}

uint32_t stack_peek(stack *s)
{
    if(stack_isEmpty(s))
    {
        return 0;
    }
    return (s->items[s->top]);
}