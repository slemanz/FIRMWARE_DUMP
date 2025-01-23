
#ifndef LED_H_
#define LED_H_

#include "stm32f401xx.h"

#define LED_PORT        GPIOB
#define LED1_PIN        GPIO_PIN_NO_1
#define LED2_PIN        GPIO_PIN_NO_2
#define LED3_PIN        GPIO_PIN_NO_14
#define LED4_PIN        GPIO_PIN_NO_15

#define DELAY_COUNT_1MS         1250U
#define DELAY_COUNT_1S          (1000U + DELAY_COUNT_1MS)
#define DELAY_COUNT_500MS       (500U + DELAY_COUNT_1MS)
#define DELAY_COUNT_250MS       (250U + DELAY_COUNT_1MS)
#define DELAY_COUNT_125MS       (125U + DELAY_COUNT_1MS)

void led_init_all(void);
void led_on(uint8_t led_no);
void led_off(uint8_t led_no);
void delay(uint32_t count);

#endif /* LED_H_ */

