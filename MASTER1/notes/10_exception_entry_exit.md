# 10. Exception Entry and Exit Sequences

## Exception Entry Sequence

1. **Set Pending Bit**: The pending bit is activated.
2. **Stacking and Vector Fetch**: The processor prepares to handle the exception.
3. **Enter Handler**: The processor enters the interrupt handler, and the active bit is set.
4. **Clear Pending Status**: The pending status is automatically cleared by the processor.
5. **Change Mode**: The processor switches to handler mode.
6. **Execute Handler Code**: The code for the handler starts running.
7. **Use MSP for Stack Operations**: The Main Stack Pointer (MSP) is used for any stack operations within the handler.

## Exception Exit Sequence

- On Cortex-M3/M4 processors, the exception return process is initiated using a special return address called EXC_RETURN.
- EXC_RETURN is created during the exception entry and is stored in the Link Register (LR).
- Writing EXC_RETURN to the Program Counter (PC) triggers the return from the exception.

--- 

Next: 