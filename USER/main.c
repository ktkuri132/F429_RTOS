#include <stm32f4xx.h>
#include <gpio.h>
#include <systick.h>
#include <FreeRTOS.h>
#include <usart.h>
#include <sys.h>
#include <OLED.h>

#include "sdram.h"
#include "gt9xxx.h"
#include "ltdc.h"
#include "lcd.h"
#include "touch.h"

void usart_send_test();
void led_test();
void usart_receive_test();
void OLED_test();
void LCD_test();


int main()
{
    
    // 串口发送测试
    //usart_send_test();
    // 串口接收测试
    //usart_receive_test();
    // LED测试
    //led_test();
    // OLED测试
    //OLED_test();
    // MPU6050测试
    //MPU6050_test();
    // LCD测试
    LCD_test();

}

void Reset_Handler();
/*
    失败，傻逼库
*/
void LCD_test()
{
    bsp_usart_1_inti(115200);
    //SDRAM_Init();
    int* a = (int*)0x08000000;
    int* b = (int*)main;
    int* c = (int*)0x08000000;
    //*a = 0x12345678;
    
    //LCD_Init();
    //gt9xxx_init();
    while (1)
    {
        //Printf(0,0,240,32,32,1,"hello,world");
        printf("%x,%x,%x\n",*a,*b,*c);
    }
    
}

/*
float Roll,Pitch,Yaw;

    用不了，傻逼库

void MPU6050_test()
{
    RCC->AHB1ENR |= 1 << 1;
    bsp_gpio_init(GPIOB, SYS_GPIO_PIN0, SYS_GPIO_MODE_OUT, SYS_GPIO_OTYPE_PP, SYS_GPIO_SPEED_HIGH, SYS_GPIO_PUPD_NONE);
    bsp_gpio_pin_set(GPIOB, SYS_GPIO_PIN0, 1);
    
    //PBout(0)=0;
    bsp_usart_1_inti(115200);
     ;//=mpu_init();
    int a= mpu_dmp_init();
    
    while (1)
    {
        
        //printf("a:%d\n",a);
        //mpu_dmp_get_data(&Roll,&Pitch,&Yaw);
        //printf("%f\n",Roll);
    }

}
*/
void OLED_test()
{
    // OLED初始化
    OLED_Init();
    OLED_Clear();
    while (1)
    {
        // OLED显示
        OLED_Printf(0, 0, OLED_8X16,"hello,world");
        // OLED更新
        OLED_Update();
    }
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