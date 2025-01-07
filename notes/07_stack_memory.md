# Stack Memory

- Stack memory is a part of the main memory (either Internal RAM or External RAM) used for temporarily storing data.
- It is primarily used during function calls and for handling interrupts or exceptions.
- Stack memory operates in a Last In First Out (LIFO) manner.
- You can access the stack using PUSH and POP instructions or other memory manipulation instructions (like LD and STR).
- The stack is managed with a Stack Pointer (SP) register, which is affected (incremented or decremented) by the PUSH and POP instructions.

### Uses of Stack Memory

1. Temporary storage of processor register values.
2. Temporary storage of local variables for functions.
3. During system exceptions or interrupts, stack memory saves the context (such as general-purpose registers and return addresses) of the currently running code.

**Note:** The stack operation mode is Full Descending (FD).

### Different Stack Model Operation