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

NVIC stands for Nested Vector Interrupt Controller. It is a peripheral of the Cortex-M processor core, used to manage 240 interrupts. 

With NVIC registers, you can:
- Enable or disable interrupts
- Set interrupts to pending status
- Read the status of active and pending interrupts
- Configure the priority and priority grouping of different interrupts

It is called "Nested" because it allows a higher priority interrupt to interrupt a lower priority interrupt handler.

Here’s a clearer and more straightforward version of your text:

## Steps to Program an MCU Peripheral Interrupt 

1. **Identify the IRQ Number**: Find the IRQ number of the peripheral in the MCU vector table. Note that IRQ numbers vary by vendor.
  
2. **Enable the IRQ**: Program the processor register to enable the IRQ. Only after enabling will the processor accept interrupts on that line.
  
3. **Set the Priority (Optional)**: You can configure the priority level for the interrupt.
  
4. **Configure the Peripheral**: Set up the peripheral (e.g., USART3) using its configuration register. For instance, USART3 will generate an interrupt on IRQ line 39 whenever it receives a packet.

5. **Handle Pending Interrupts**: When the interrupt is triggered, it will be recorded as pending in the processor's NVIC. The IRQ handler will only run if the new interrupt's priority is higher than the currently executing handler. If not, the new interrupt will remain pending.

6. **Responding to Disabled IRQs**: If the peripheral generates an interrupt while the IRQ is disabled, it will still be recorded as pending in the NVIC. Once the IRQ is enabled, the Interrupt Service Routine (ISR) will execute if the new interrupt's priority is higher than the already active ISR   .

Here the example: [pend.c](../app/Src/pend.c)

---

Next: [9. Interrupt Priority and Configuration](09_interrupt_priority.md)
