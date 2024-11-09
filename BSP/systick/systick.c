#include <stm32f4xx.h>
#include <systick.h>

void bsp_systick_init()
{
    SysTick->LOAD = 0X00FFFFFF; /* 设置重装数值, 24位 */
    SysTick->VAL = 0X00;        /* 清空计数器 */
    SysTick->CTRL = 0X00000003; /* 使能, 使用HCLK/8, 中断 */
}

void bsp_systick_delay_us(uint32_t nus)
{
    SysTick->LOAD = nus * 21; 
    SysTick->VAL = 0x00; 
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; 
    while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk))
    {
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; 
    SysTick->VAL = 0X00;
}

void bsp_systick_delay_ms(uint32_t nms)
{
    uint32_t i;
    for (i = 0; i < nms; i++)
    {
        bsp_systick_delay_us(1000);
    }
}
