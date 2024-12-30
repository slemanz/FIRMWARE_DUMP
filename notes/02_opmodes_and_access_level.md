# 2. Operational Modes and Access Level

## Operational Modes

The ARM Cortex-M processors operate in two distinct modes:

- **Thread Mode**
- **Handler Mode**

Application code executes in **Thread Mode**, often referred to as **User Mode**. This is where the majority of your application logic resides, allowing for standard execution of tasks and processes.

In contrast, **Handler Mode** is reserved for handling exceptions and interrupts. Whenever an event such as a system exception or an external interrupt occurs, the processor transitions from Thread Mode to Handler Mode. This mode allows the processor to execute the Interrupt Service Routine (ISR) associated with the specific interrupt or exception.

It's important to note that the processor starts in Thread Mode. The switch to Handler Mode is automatic and is part of the processor's interrupt management system, ensuring that critical events are promptly addressed while maintaining the integrity of ongoing operations. Once the ISR has completed, the processor returns to Thread Mode to resume normal execution of the application code.

An example code can be seen [here](../app/Src/opmodes.c).

