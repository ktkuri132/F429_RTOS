#include <stm32f4xx.h>
#include <gpio.h>
#include <systick.h>
#include <FreeRTOS.h>
#include <usart.h>
#include <sys.h>

extern uint8_t UART_End;

void usart_send_test();
void led_test();
void usart_receive_test();


int main()
{
    
    // 串口发送测试
    //usart_send_test();
    // 串口接收测试
    usart_receive_test();
    // LED测试
    //led_test();
}

void usart_receive_test()
{
    // 中断初始化
    NVIC_Configuration();
    // 串口初始化
    bsp_usart_1_inti(115200);

    //printf("root@stm32:%s\r\n");
    while (1)
    {   
        
    }
}

void usart_send_test()
{
    // 串口初始化
    bsp_usart_1_inti(115200);
    while (1)
    {
        printf("hello world!\r\n");
        bsp_systick_delay_ms(1000);
    }
}

void led_test()
{

    // 使能GPIOB时钟
    RCC->AHB1ENR |= 1 << 1;

    bsp_gpio_init(GPIOB, SYS_GPIO_PIN0, SYS_GPIO_MODE_OUT, SYS_GPIO_OTYPE_PP, SYS_GPIO_SPEED_HIGH, SYS_GPIO_PUPD_NONE);
    
    while (1)
    {
        bsp_gpio_pin_set(GPIOB, SYS_GPIO_PIN0, 0);
        bsp_systick_delay_ms(500);
        bsp_gpio_pin_set(GPIOB, SYS_GPIO_PIN0, 1);
        bsp_systick_delay_ms(500);
    }
    
}