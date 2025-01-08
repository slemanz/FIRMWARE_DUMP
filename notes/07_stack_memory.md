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


- **Full Ascending Stack**: This stack is completely filled, and items are added in ascending order. For example, if you add numbers, they will go in like this: 1, 2, 3, ... up to the maximum capacity.

- **Full Descending Stack**: Similar to the Full Ascending Stack, but items are arranged in descending order. So, if you add numbers, they will stack as 3, 2, 1, ... down to the lowest value.

- **Empty Ascending Stack**: When elements are added, they grow upwards in memory, meaning the Stack Pointer (SP) is initially at the lowest memory address. As items are pushed onto the stack, the SP moves up, pointing to the next available slot. 

- **Empty Descending Stack**: Like the Empty Ascending Stack, but the SP starts at a higher memory address and as items are added, it moves downward.

### Stack Placement

There are mainly 2 types:

1. Stack place after heap.
2. Stack place in the end of RAM

### Banked Stack Pointers

Cortex Mx processors have three stack pointers:
- SP (R13)
- MSP (Main Stack Pointer)
- PSP (Processor Stack Pointer)

SP is known as the current stack pointer.

After a processor reset, the MSP is selected as the current stack pointer by default, meaning SP copies the contents of MSP. 

In thread mode, you can switch the current stack pointer to PSP by configuring the SPSEL bit in the control register. However, in handler mode, the processor always uses MSP as the current stack pointer. This means that changing the SPSEL bit while in handler mode has no effect; the write will be ignored.

The MSP is automatically initialized by the processor after a reset by reading the contents at address 0x00000000. 

If you want to use PSP, make sure to initialize it to a valid stack pointer in your code.

### Example


