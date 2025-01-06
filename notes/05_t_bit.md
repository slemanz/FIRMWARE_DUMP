# T Bit

Many ARM processors support **ARM-Thumb interworking**, which allows for switching between ARM and Thumb states. The processor must be in ARM state to execute instructions from the ARM Instruction Set Architecture (ISA) and in Thumb state to execute instructions from the Thumb ISA.

The **T bit** in the **Execution Program Status Register (EPSR)** is crucial in determining the instruction set that the processor will execute:
- If the T bit is set to **1**, the processor presumes that the next instruction is from the Thumb ISA.
- Conversely, if the T bit is reset to **0**, the processor assumes that the next instruction is from the ARM ISA.

It’s important to note that Cortex-Mx processors do not support the ARM state; therefore, the T bit must always be **1**. Failing to maintain this requirement raises a **Usage Fault** exception.

Additionally, the least significant bit (bit 0) of the Program Counter (PC) is directly linked to the T bit. When a value or address is loaded into the PC, the least significant bit of that value is captured in the T bit. As a result, any address placed in the PC must have its least significant bit set to **1**. This is typically managed by the compiler, so programmers often do not need to be concerned about it.

This explains why all vector addresses in the vector table are incremented by **1**.

---

Next: 