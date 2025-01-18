#include "stm32f401xx.h"
#include <stdio.h>
#include "main.h"

void uart2_init_pins(void);
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack);
void init_tasks_stack(void);

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


int main(void)
 {

    init_scheduler_stack(SCHED_STACK_START);
    uart2_init_pins();
    uart2_init();

    task_handlers[0] = (uint32_t)task1_handler;
    task_handlers[1] = (uint32_t)task2_handler;
    task_handlers[2] = (uint32_t)task3_handler;
    task_handlers[3] = (uint32_t)task4_handler;

    init_tasks_stack();

    systick_init(TICK_HZ);

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

void SysTick_Handler(void)
{
    
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