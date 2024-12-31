# 2. Operational Modes and Access Level

## Operational Modes

The ARM Cortex-M processors operate in two distinct modes:

- **Thread Mode**
- **Handler Mode**

Application code executes in **Thread Mode**, often referred to as **User Mode**. This is where the majority of your application logic resides, allowing for standard execution of tasks and processes.

In contrast, **Handler Mode** is reserved for handling exceptions and interrupts. Whenever an event such as a system exception or an external interrupt occurs, the processor transitions from Thread Mode to Handler Mode. This mode allows the processor to execute the Interrupt Service Routine (ISR) associated with the specific interrupt or exception.

It's important to note that the processor starts in Thread Mode. The switch to Handler Mode is automatic and is part of the processor's interrupt management system, ensuring that critical events are promptly addressed while maintaining the integrity of ongoing operations. Once the ISR has completed, the processor returns to Thread Mode to resume normal execution of the application code.

An example code can be seen [here](../app/Src/opmodes.c).

## Access Levels

The processor supports two access levels:

- **PAL (Privileged Access Level)**
- **NPAL (Non-Privileged Access Level)**

When your code is executed in **PAL**, it has unrestricted access to all processor-specific resources and restricted registers. This level is typically reserved for critical system functions, allowing complete control over the hardware.

In contrast, code running in **NPAL** may have limited access, prohibiting interactions with certain restricted registers. This access control is vital for preventing unintentional modifications to sensitive system components.

By default, your application code operates in **PAL** when the processor is in **Thread Mode**. However, it is possible to switch from PAL to NPAL while remaining in Thread Mode. Once this switch occurs, returning to PAL is not permitted unless the processor’s operational mode is changed to **Handler Mode**. 

It’s important to note that all code execution in **Handler Mode** is always conducted at PAL. 

To switch between access levels, you can utilize the processor's control register, enabling you to manage access rights as needed based on your application's requirements.

## Core Registers