#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Maximum size of the stack

typedef struct {
    uint32_t items[MAX_SIZE];
    int top;
} stack;

// Function declarations
stack* stack_create(void);
void stack_destroy(stack *s);

void initstack(stack *s);
bool isfull(stack *s);
bool isempty(stack *s);
bool push(stack *s, uint32_t item);
uint32_t pop(stack *s);
uint32_t peek(stack *s);

#endif // STACK_H