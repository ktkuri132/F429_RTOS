#include <stm32f4xx.h>
#include <gpio.h>

void main()
{
    bsp_gpio_init(GPIOB, SYS_GPIO_PIN0, SYS_GPIO_MODE_OUT, SYS_GPIO_OTYPE_PP, SYS_GPIO_SPEED_HIGH, SYS_GPIO_PUPD_NONE);
    while (1)
    {
        bsp_gpio_pin_set(GPIOB, SYS_GPIO_PIN0, 1);
        bsp_systick_delay_ms(500);
        bsp_gpio_pin_set(GPIOB, SYS_GPIO_PIN0, 0);
        bsp_systick_delay_ms(500);
    }
    
}