#include "stm32f401xx.h"
#include <stdio.h>

extern int __io_putchar(int ch)
{
    uart2_write_byte((uint8_t)ch);
    return ch;

}

// this function executes in THREAD MODE of the processor
void generate_interrupt()
{
    uint32_t *pSTIR  = (uint32_t*)0xE000EF00;
    uint32_t *pISER0 = (uint32_t*)0xE000E100;

    // enable IRQ3 interrupt
    *pISER0 |= (1 << 3);

    // generate an interrupt from software for IRQ3
    *pSTIR = (3 & 0x1FF);
}



// this function executes in THREAD MODE of the processor
int main(void)
 {
    uart2_init_pins();
    uart2_init();

    printf("In thread mode : before interrupt\n");

    printf("In thread mode : after interrupt\n");

    while (1)
    {
        
    }
}

// this function(ISR) executes in HANDLER MODE of the processor 
void EXTI22_RTC_WKUP_IRQHandler()
{
    printf("In handler mode : ISR\n");
}