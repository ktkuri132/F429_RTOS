#ifndef __NVIC_
#define __NVIC_

#include <stm32f4xx.h>
#include <gpio.h>
#include <systick.h>

#include <usart.h>
#include <sys.h>
#include <OLED.h>

#include "sdram.h"
#include "gt9xxx.h"
#include "ltdc.h"
#include "lcd.h"
#include "touch.h"

#include <lcd_gui.h>

void NVIC_Configuration(void);


#endif