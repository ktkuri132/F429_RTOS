#ifndef __MPU6050_
#define __MPU6050_

typedef unsigned char u8;
typedef unsigned short u16;

#include <i2clib.h>

#define MPU6050_ADDR 0x68

#define MPU_IIC_PORT i2c1
#define MPU_SCL 3
#define MPU_SDA 2

#define MPU_Write_Byte(reg,data) IIC_WriteCommand(MPU_IIC_PORT,MPU6050_ADDR,reg,data)
#define MPU_Write_Len(addr,reg,len,buf) IIC_WriteData(MPU_IIC_PORT,addr,reg,buf,len)
#define MPU_Read_Len(addr,reg,len,buf) IIC_ReadData(MPU_IIC_PORT,addr,reg,buf,len)
#define MPU_IIC_Init() IIC_GPIO_Init(MPU_IIC_PORT,MPU_SCL,MPU_SDA)

u8 MPU_Read_Byte(u8 reg);


#endif
