#include "stm32f401xx.h"
#include <stdio.h>
#include <stdlib.h>
#include "system.h"

struct Stack{
    int top;
    int capacity;
    int *array;
};

typedef struct Stack stackType;

stackType* stack_create(int capacity);
void stack_double_size(stackType *stack);
int stack_isFull(stackType *stack);
int stack_isEmpty(stackType *stack);
int stack_getSize(stackType *stack);
void stack_push(stackType *stack, int data);
int stack_pop(stackType *stack);
int stack_peek(stackType *stack);
void stack_delete(stackType *stack);

int main(void)
{
    system_init();
    printf("\n");
    printf("Init..\n");

    int capacity = 7;
    stackType *temperature_values = stack_create(capacity);

    for(int i = 0; i <= 2*capacity; i++)
    {
        stack_push(temperature_values, (250+i));
    }

    printf("Top element is %d\n\r", stack_peek(temperature_values));
    printf("Stack size is %d\n\r", stack_getSize(temperature_values));
    printf("\n\r");

    for(int i = 0; i <= 2*capacity; i++)
    {
        printf("Stack popped element is: %d\n\r", stack_pop(temperature_values));
    }

    if(stack_isEmpty(temperature_values))
    {
        printf("Stack is empty\n\r");
    }else
    {
        printf("Stack is not empty\n\r");
    }

    while (1)
    {
    }
}

stackType* stack_create(int capacity)
{
    stackType *stack = (stackType*)malloc(sizeof(stackType));

    if(!stack)
    {
        printf("Not able to create stack!\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = malloc(stack->capacity*sizeof(int));

    if(!stack->array)
    {
        printf("Not able to create array of this size.\n\r");
        free(stack);
        return NULL;
    }

    return stack;
}

void stack_double_size(stackType *stack)
{
    stack->capacity *= 2;
    stack->array = realloc(stack->array, stack->capacity*sizeof(int));
}

int stack_isFull(stackType *stack)
{
    return (stack->top == stack->capacity-1);
}

int stack_isEmpty(stackType *stack)
{
    return (stack->top == -1);
}

int stack_getSize(stackType *stack)
{
    return (stack->top + 1);
}

void stack_push(stackType *stack, int data)
{
    if(stack_isFull(stack))
    {
        stack_double_size(stack);
    }

    stack->array[++stack->top] = data;
}

int stack_pop(stackType *stack)
{
    if(stack_isEmpty(stack))
    {
        printf("Stack is empty");
        return -999;
    }
    return (stack->array[stack->top--]);
}

int stack_peek(stackType *stack)
{
    if(stack_isEmpty(stack))
    {
        printf("Stack is empty");
        return -999;
    }
    return (stack->array[stack->top]);
}

void stack_delete(stackType *stack)
{
    if(stack)
    {
        if(stack->array)
        {
            free(stack);
        }

        free(stack);
    }
}