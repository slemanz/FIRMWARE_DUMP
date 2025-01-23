#include "led.h"

void delay(uint32_t count)
{
    for(uint32_t i = 0; i < count; i++)
    {
        __asm("NOP");
    }
}

void led_init_all(void)
{
    GPIO_Handle_t GpioLed;
	GpioLed.pGPIOx = LED_PORT;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = LED1_PIN;
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GpioLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

    GPIO_Init(&GpioLed);
    GPIO_WriteToOutputPin(LED_PORT, LED1_PIN, GPIO_PIN_RESET);

    GpioLed.GPIO_PinConfig.GPIO_PinNumber = LED2_PIN;
    GPIO_Init(&GpioLed);
    GPIO_WriteToOutputPin(LED_PORT, LED2_PIN, GPIO_PIN_RESET);

    GpioLed.GPIO_PinConfig.GPIO_PinNumber = LED3_PIN;
    GPIO_Init(&GpioLed);
    GPIO_WriteToOutputPin(LED_PORT, LED3_PIN, GPIO_PIN_RESET);

    GpioLed.GPIO_PinConfig.GPIO_PinNumber = LED4_PIN;
    GPIO_Init(&GpioLed);
    GPIO_WriteToOutputPin(LED_PORT, LED4_PIN, GPIO_PIN_RESET);
}

void led_on(uint8_t led_no)
{
    GPIO_WriteToOutputPin(LED_PORT, led_no, GPIO_PIN_SET);

}
void led_off(uint8_t led_no)
{
    GPIO_WriteToOutputPin(LED_PORT, led_no, GPIO_PIN_RESET);
}