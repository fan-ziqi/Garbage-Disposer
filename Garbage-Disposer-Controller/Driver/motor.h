/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MOTOR_H
#define __MOTOR_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

void Motor_Init(uint8_t freq_khz); //电机PWM控制初始化
void Motor_Dangban_L_SetSpeed(int16_t speed);   //电机1控制
void Motor_Dangban_R_SetSpeed(int16_t speed);   //电机2控制
void Motor_Fensui_SetSpeed(int16_t speed);   //电机3控制
//void MOTOR4_SetSpeed(int16_t speed);   //电机4控制

#endif
