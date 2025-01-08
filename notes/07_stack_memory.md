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

### MSP and PSP Summary

1. Cortex-M processors have two stack pointer registers.
2. **Main Stack Pointer (MSP)**: This is the default stack pointer used after a reset. It is used for all exception and interrupt handlers and for code running in thread mode.
3. **Process Stack Pointer (PSP)**: This is an alternate stack pointer used only in thread mode. It is typically used for application tasks in embedded systems and embedded operating systems.
4. After power-up, the processor automatically initializes the MSP by reading the first location of the vector table.

To change the stack pointer, you can use the MSR and MRS instructions in assembly code to access MSP and PSP. In a 'C' program, you can write a naked function (a 'C' function without prologue and epilogue sequences) to change the currently selected stack pointer.

### Function Call

Procedure Call Standard for the Arm Architecture (AAPCS)
- When a 'C' compiler compiles code for the ARM architecture, it should follow the AAPCS specification to generate code
- According to this standard, a 'C' function can modify the registers RO, R1, R2, R3, R14(LR) and PSR and it's not the responsibility of the function to save these registers before any modification
- If a function wants to make use of R4 to R11 registers, then it's the responsibility of the function to save its previous contents before modifying those registers and retrieve it back before exiting the function
