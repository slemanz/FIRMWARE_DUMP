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

