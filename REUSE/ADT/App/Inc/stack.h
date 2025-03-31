#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 10 // Maximum size of the stack

typedef struct mys stack;



// Function declarations
stack* stack_create(void);
void stack_destroy(stack *s);


bool stack_isFull(stack *s);
bool stack_isEmpty(stack *s);
bool stack_push(stack *s, uint32_t item);
uint32_t stack_pop(stack *s);
uint32_t stack_peek(stack *s);

#endif // STACK_H