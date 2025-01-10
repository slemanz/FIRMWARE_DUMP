#include "stm32f401xx.h"
#include <stdio.h>

/*
    Exemple: Pend
 */

void uart2_init_pins(void);

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

#define USART3_IRQNO        39

int main(void)
 {

    uart2_init_pins();
    uart2_init();

    // 1. Manually pend the pending bit for USART3 IRQ number in NVIC
    uint32_t *pISPR1 = (uint32_t*)0xE000E204;
    *pISPR1 |= (1 << (USART3_IRQNO % 32));

    // 2. Enable the USART3 IRQ number in NVIC
    uint32_t *pISER = (uint32_t *)0xE000E104;
    *pISER |= (1 << (USART3_IRQNO % 32));


    while (1)
    {
        delay_cycles(16000000);
    }
}

void USART3_IRQHandler(void)
{
    printf("In usart3 isr\n");
}