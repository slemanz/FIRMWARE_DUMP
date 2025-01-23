#ifndef MAIN_H_
#define MAIN_H_

#define MAX_TASKS               5

/* some stack memory calculations */
#define SIZE_TASK_STACK         1024U
#define SIZE_SCHED_STACK        1024U

#define SRAM_START              0x20000000U
#define SIZE_SRAM               ((96)*(1024))
#define SRAM_END                (SRAM_START + SIZE_SRAM)

#define T1_STACK_START          (SRAM_END)
#define T2_STACK_START          ((SRAM_END) - (1 * SIZE_TASK_STACK))
#define T3_STACK_START          ((SRAM_END) - (2 * SIZE_TASK_STACK))
#define T4_STACK_START          ((SRAM_END) - (3 * SIZE_TASK_STACK))
#define IDLE_STACK_START        ((SRAM_END) - (4 * SIZE_TASK_STACK))

#define SCHED_STACK_START       ((SRAM_END) - (5 * SIZE_TASK_STACK))



#define DUMMY_XPSR      0x01000000U

#define TASK_READY_STATE        0x00
#define TASK_BLOCKED_STATE      0xFF

void update_global_tick_count(void);

void uart2_init_pins(void);
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack);
void init_tasks_stack(void);
void enable_processor_faults(void);
void switch_sp_to_psp(void);
uint32_t get_psp_value(void);

void idle_task(void);
void task_delay(uint32_t tick_count);
void schedule(void);



#endif /* MAIN_H_ */