/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SERVO_H
#define __SERVO_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

//X-SOFT�ӿں���
void Servo_Dangban_Init(void);                 //���AB�ӿڳ�ʼ��
void Servo_Dangban_L_SetAngle(uint16_t angle);    //���A����   
void Servo_Dangban_R_SetAngle(uint16_t angle);    //���B����

void Servo_Laji_Init(void);                 //���CD�ӿڳ�ʼ��
void Servo_Laji_L_SetAngle(uint16_t angle);    //���C���� 
void Servo_Laji_R_SetAngle(uint16_t angle);    //���D���� 

void Servo_Kaimen_Init(void);               //���EFGH�ӿڳ�ʼ��
void Servo_Kaimen_SetAngle(uint16_t angle);    //���E����
void Servo_test_SetAngle(uint16_t angle);    //���F���� 

//void SERVO_GH_Init(void);               //���EFGH�ӿڳ�ʼ��
//void SERVO_G_SetAngle(uint16_t angle);    //���G����
//void SERVO_H_SetAngle(uint16_t angle);    //���H���� 

#endif
