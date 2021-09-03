/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SERVO_H
#define __SERVO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

//X-SOFT接口函数
void Servo_Dangban_Init(void);                 //舵机AB接口初始化
void Servo_Dangban_L_SetAngle(uint16_t angle);    //舵机A控制   
void Servo_Dangban_R_SetAngle(uint16_t angle);    //舵机B控制

void Servo_Laji_Init(void);                 //舵机CD接口初始化
void Servo_Laji_SetAngle(uint16_t angle);    //舵机C控制 

void Servo_Kaimen_Init(void);               //舵机EFGH接口初始化
void Servo_Kaimen_SetAngle(uint16_t angle);    //舵机E控制

#endif
