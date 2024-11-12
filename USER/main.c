#include <sys.h>
#include <FreeRTOS.h>
#include <task.h>
void usart_send_test();
void led_test();
void usart_receive_test();
void OLED_test();
void LCD_test();

// 创建任务句柄
TaskHandle_t StartTask_Handler;
TaskHandle_t LCD_test_Handler;
TaskHandle_t USART_test_Handler;
TaskHandle_t LED_Handler;

void StartTask(void *pvParameters)
{
    taskENTER_CRITICAL();
    NVIC_Configuration();
    
    
    
    //xTaskCreate((TaskFunction_t)LCD_test, "LCD_test", 1024, NULL, 1, &LCD_test_Handler);
    xTaskCreate((TaskFunction_t)usart_receive_test, "USART_test", 1024, NULL, 2, &USART_test_Handler);
    xTaskCreate((TaskFunction_t)led_test, "LED_test", 1024, NULL, 3, &LED_Handler);
    vTaskDelete(StartTask_Handler);
    taskEXIT_CRITICAL();
}

int main()
{
    
    SDRAM_Init();
    xTaskCreate((TaskFunction_t)StartTask, "StartTask", 1024, NULL, 1, &StartTask_Handler);
    vTaskStartScheduler();
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
    //LCD_test();
}

uint8_t act_sign_1,act_sign_2;
void LCD_test()
{
    
    LCD_Init();
    gt9xxx_init();
    //LCD_EXTI_Configuration();
    while (1)
    {
        tp_dev.scan(0);     //读坐标
        Button_check(&act_sign_1,0,360,250,100,50,"Enter");
        Button_check(&act_sign_2,1,520,250,100,50,"Esc");
        //Printf(0,0,240,32,32,1,"hello,world");
        //printf("%x,%x\n",*a,*b);
    }
    
}


void EXTI9_5_IRQHandler(void)
{
    // Check if EXTI_Line7 is asserted
    if (EXTI->PR & EXTI_PR_PR7)
    {
        tp_dev.scan(0);     //读坐标
        Button_check(&act_sign_1,0,360,250,100,50,"Enter");
        Button_check(&act_sign_2,1,520,250,100,50,"Esc");
        // Clear the EXTI line pending bit
        EXTI->PR = EXTI_PR_PR7;
    }
}

int a;

void button_response(uint8_t *act_sign)
{
    switch (*act_sign)
    {
        case 0:
        {
            a +=2;
            Printf(0,64,240,32,32,0,"a:%d",a); 
            printf("%d\r\n",a);
        }   
        break;
        
        case 1:
        {
            a--;
            Printf(0,64,240,32,32,0,"a:%d",a); 
            printf("%d\r\n",a);
        }
        break;
        default:
            break;
    }

}



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
    //NVIC_Configuration();
    // 串口初始化
    bsp_usart_1_inti(115200);
    int hour=0,min=0,sec=0;
    
    while (1)
    {   
        printf("%d:%d:%d\r\n",hour,min,sec++);
        vTaskDelay(1000);
        if(sec==60)
        {
            sec=0;
            min++;
            if(min==60)
            {
                min=0;
                hour++;
                if(hour==24)
                {
                    hour=0;
                }
            }
        }
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
        vTaskDelay(500);
        //bsp_systick_delay_ms(500);
        bsp_gpio_pin_set(GPIOB, SYS_GPIO_PIN0, 1);
        vTaskDelay(500);
        //bsp_systick_delay_ms(500);
    }
    
}