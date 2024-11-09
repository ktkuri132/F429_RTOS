#ifndef  __HARDI2C_
#define  __HARDI2C_

#include <stm32f4xx.h>

// 定义部分硬件I2C端口
#define I2C1_B6C7D
#define I2C1_B9C8D
#define I2C2_B10C11D

#ifdef I2C1_B6C7D
#define SCL 6
#define SDA 7
#endif


#endif