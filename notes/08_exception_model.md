# 8. Exception Model

An exception is an event that disrupts the normal operation of a program by changing the processor's operational mode. There are two types of exceptions:

1. **System Exceptions**: These are generated internally by the processor.
2. **Interrupts**: These come from external sources to the processor.

When the processor encounters an exception, it switches to "Handler mode." 

Cortex-M processors support a total of 15 system exceptions and 240 interrupts, making for a total of 255 exceptions.

## Different System Exceptions


