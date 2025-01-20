#include "stm32f401xx.h"
#include <stdio.h>
#include "main.h"

void uart2_init_pins(void);
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack);
void init_tasks_stack(void);
void enable_processor_faults(void);
void switch_sp_to_psp(void);
uint32_t get_psp_value(void);

extern int __io_putchar(int ch)
{
    uart2_write_byte((uint8_t)ch);
    return ch;

}

// Function delay
void delay_cycles(uint32_t cycles)
{
    while (cycles-- > 0) {
        __asm("NOP"); // No operation for delay
    }
}



void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);


uint32_t psp_of_tasks[MAX_TASKS] = {T1_STACK_START, T2_STACK_START, T3_STACK_START, T4_STACK_START};
uint32_t task_handlers[MAX_TASKS];
uint8_t current_task = 0; // task1 is running


int main(void)
 {
    uart2_init_pins();
    uart2_init();

    enable_processor_faults();

    init_scheduler_stack(SCHED_STACK_START);

    task_handlers[0] = (uint32_t)task1_handler;
    task_handlers[1] = (uint32_t)task2_handler;
    task_handlers[2] = (uint32_t)task3_handler;
    task_handlers[3] = (uint32_t)task4_handler;

    init_tasks_stack();

    systick_init(TICK_HZ);

    switch_sp_to_psp();
    task1_handler();

    while (1)
    {
        delay_cycles(16000000);
    }
}

void task1_handler(void)
{
    printf("This is task 1\n");
    while(1)
    {

    }
}

void task2_handler(void)
{
    printf("This is task 2\n");
    while(1)
    {

    }
}

void task3_handler(void)
{
    printf("This is task 3\n");
    while(1)
    {

    }
}

void task4_handler(void)
{
    printf("This is task 4\n");
    while(1)
    {

    }
}


__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack)
{
    //__asm volatile("MSR MSP, R0"); // here R0 is the first argument
    __asm volatile("MSR MSP, %0": : "r" (sched_top_of_stack): ); // other way
    __asm volatile("BX LR"); // return from function call
}


void init_tasks_stack(void)
{
    uint32_t *pPSP;

    for(int i = 0; i < MAX_TASKS; i++)
    {
        pPSP = (uint32_t*)psp_of_tasks[i];

        pPSP--;
        *pPSP = DUMMY_XPSR;

        pPSP--; // PC
        *pPSP = task_handlers[i];

        pPSP--; // LR
        *pPSP = 0xFFFFFFFD;

        for(int j = 0; j < 13; j++) // Rx
        {
            pPSP--;
            *pPSP = 0;
        }

        psp_of_tasks[i] = (uint32_t)pPSP;


    }
}

uint32_t get_psp_value(void)
{
    return psp_of_tasks[current_task];
}

__attribute__((naked)) void switch_sp_to_psp(void)
{
    // 1, initialize the PSP with TASK1 stack start

    // get the value of PSP with TASK1 stack start address
    __asm volatile ("PUSH {LR}"); // preserve LR which connects back to main()
    __asm volatile ("BL get_psp_value");
    __asm volatile ("MSR PSP, R0"); // initialize psp
    __asm volatile ("POP {LR}"); // pops back LR value

    // 2. Change the SP to PSP using CONTROL register
    __asm volatile("MOV R0, #0x02");
    __asm volatile("MSR CONTROL, R0");
    __asm volatile("BX LR");

}

void SysTick_Handler(void)
{
    /* Save the context of the current task */

    // 1. Get current running task PSP value
    // 2. Using that PSP value to store SF2 (R4 to R11)
    // 3. Save the current value of PSP

    /* Retrieve the context of the next task */

    // 1. Decide next task to run
    // 2. Get its past PSP value
    // 3. Using that PSP value retrieve SF2 (R4 to R11) 
    // 4. Update PSP and exit

}

void enable_processor_faults(void)
{
    uint32_t *pSHCSR = (uint32_t*)0xE000ED24;

    *pSHCSR |= (1 << 16); // mem manage
    *pSHCSR |= (1 << 17); // bus fault
    *pSHCSR |= (1 << 18); // usage fault
}


// implementation the fault handlers
void HardFault_Handler(void)
{
    printf("Exception : Hardfault\n");
    while(1);
}

void MemManage_Handler(void)
{
    printf("Exception: MemManage\n");
    while(1);
}


void BusFault_Handler(void)
{
    printf("Exception: BusFault\n");
    while(1);
}