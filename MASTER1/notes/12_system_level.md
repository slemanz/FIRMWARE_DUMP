# 12. System Level Services

## Exceptions for System-Level Services

- The ARM Cortex-Mx processor supports two important system-level service exceptions: SVC (Supervisor Call) and PendSV (Pendable Service).
- Supervisor Calls are used to request privileged operations or access to system resources from an operating system.
- The SVC exception is primarily used in an operating system environment. For example, a less privileged user task can trigger the SVC exception to access system-level services, such as device drivers and peripherals, from the OS kernel.
- PendSV is used to manage context switching between two or more tasks when no other exceptions are active in the system.

## SVC (Supervisor Call) Instruction

- SVC is a Thumb ISA instruction that triggers the SVC exception.
- In an RTOS (Real-Time Operating System) context, user tasks execute the SVC instruction with an associated argument to request privileged resources from the kernel.
- Unprivileged user tasks use the SVC instruction to switch the processor to privileged mode, allowing them access to privileged resources like peripherals.
- The SVC instruction is always accompanied by a number that helps the kernel identify the type of request.
- The SVC handler executes immediately after the SVC instruction (without delay), unless a higher priority exception occurs at the same time.

## Methods to Trigger the SVC Exception

There are two ways to trigger the SVC exception:
1. Directly execute the SVC instruction with an immediate value (e.g., `SVC #0x04` in assembly). This method is efficient in terms of latency.
2. Set the exception pending bit in the **System Handler Control and State Register** (this method is less common).

## How to Extract the SVC Number

The SVC instruction contains an embedded number, commonly known as the SVC number. 

In the SVC handler, follow these steps to extract the SVC number: 

1. Fetch the opcode of the SVC instruction from program memory.
2. To get this opcode, you need the value of the Program Counter (PC) at the time the user code was interrupted by the SVC exception. 
3. The PC value is stored on the stack as part of the exception entry sequence by the processor.

Here a [example code of svc](../app/Src/svc.c)

## PendSV Exception

The PendSV exception is type 14 and has a programmable priority level. 

This exception is triggered by setting its pending status in the **Interrupt Control and State Register** of the processor. 

Invoking the PendSV exception is a way to prompt the preemptive kernel to perform a context switch in an operating system (OS) environment. The PendSV handler is assigned the lowest priority level, ensuring that it executes after higher priority tasks are completed.

### Typical Use of PendSV

- The PendSV exception is usually triggered within a higher priority exception handler and is executed once that higher priority handler finishes.
- This allows the PendSV handler to run after all other interrupt processing tasks are completed, making it effective for context switching.
- Context switching is a vital operation in many OS designs, and using PendSV for this purpose enhances efficiency in "interrupt noisy" environments.
- In such environments, it is important to delay context switching until all interrupt requests (IRQs) have been handled.

---

Next: [13. Task Schedular](13_task.md)