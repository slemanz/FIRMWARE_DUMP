# 4. Reset Sequence

1. When the processor is reset, the Program Counter (PC) is initialized with the value **0x00000000**.
2. The processor then reads the value from memory location **0x00000000** into the **Main Stack Pointer (MSP)**. This step initializes the stack pointer.
3. Next, the processor retrieves the value from memory location **0x00000004** into the PC. This value corresponds to the address of the **reset handler**.
4. The PC then jumps to the reset handler, beginning the execution of the initialization routine.
5. The reset handler is a function written in either C or assembly that is responsible for performing the necessary initializations for the application.
6. Finally, within the reset handler, you will call the **main()** function of your application to begin regular operation.

The vector table directs the processor to execute the reset handler immediately following a reset, leading to the flow: **Vector Table** -> **startup file/Reset_handler()** → **main.c/main()**.

## Responsibilities of the Reset Handler Before Calling Main

During the reset process, the reset handler is responsible for:
- Initializing data sections
- Setting up the .bss section
- Initializing the C standard library (if necessary)
- Calling the **main()** function of the application

This structured sequence ensures that the system is properly configured before entering the primary application logic.

--- 

Next: [5. T Bit](05_t_bit.md)