/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MOTOR_H
#define __MOTOR_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

void Motor_Init(uint8_t freq_khz); //���PWM���Ƴ�ʼ��
void Motor_Dangban_L_SetSpeed(int16_t speed);   //���1����
void Motor_Dangban_R_SetSpeed(int16_t speed);   //���2����
void Motor_Fensui_SetSpeed(int16_t speed);   //���3����
//void MOTOR4_SetSpeed(int16_t speed);   //���4����

#endif
