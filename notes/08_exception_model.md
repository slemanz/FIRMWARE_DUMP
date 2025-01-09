# 8. Exception Model

An exception is an event that disrupts the normal operation of a program by changing the processor's operational mode. There are two types of exceptions:

1. **System Exceptions**: These are generated internally by the processor.
2. **Interrupts**: These come from external sources to the processor.

When the processor encounters an exception, it switches to "Handler mode." 

Cortex-M processors support a total of 15 system exceptions and 240 interrupts, making for a total of 255 exceptions.

## Different System Exceptions

Cortex-M processors support up to 15 system exceptions. The first exception is the reset exception. Currently, 9 system exceptions are implemented, while 6 are reserved for future use. Exception number 16 is for interrupt 1 (IRQ 1).

## System Exception Control Registers

The System Control Block (SCB) provides information about the system and controls system exceptions. It includes configuration, control, and reporting features. You can find more details in the ARM Cortex-M4 generic user guide.

**SCB Registers Allow You To:**
- Enable fault handlers
- Check the status of pending fault exceptions
- Trap the processor for divide-by-zero errors and unaligned data access attempts
- Control sleep and wakeup settings
- Set the priority for system exceptions
- Manage the control and status of the SysTick timer

## NVIC