#include "behaviour.h"
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>

#include "sys.h"    //ϵͳ����
#include "delay.h"  //�����ʱ
#include "led.h"    //LED�ƿ���
#include "key.h"    //������� 
#include "motor.h"    //ֱ��������ٿ���
#include "servo.h"    //�������
#include "tim.h"      //��ʱ��

#define TIME_OF_LENGQUE 10000
#define TIME_OF_DANGBAN_DOWN 5000
#define SPEED_OF_FENSUI 1000
#define TIME_OF_FENSUI 20000
#define TIME_OF_DIANDIANLE 20000

//�����ʼ��
void All_Init(void)
{
	//����λ����֧����
	Servo_Dangban_L_SetAngle(600);//TODO�ĽǶ�
	Servo_Dangban_R_SetAngle(600);
	
	//Ȼ���ٰѵ��彵����
	while((!KEY_Dangban_Down_L())||(!KEY_Dangban_Down_R()))
    {
		//TODO����������
	}
	
	//�ߵ��ֹ���
	Servo_Kaimen_SetAngle(600);
	
	//����������
	Servo_Laji_SetAngle(600);
	
	//������զ�죿
}

//��һ������Һ���룬ˮ�ͷ���
void GuYeFenLi(void)
{
	//��Һ����
	//�ѵ���������
	while((!KEY_Dangban_Up_L())||(!KEY_Dangban_Up_R()))
    {
		//TODO����������
	}
	
	//��������Ƭ�ͷ���
	//TODO
	delay_ms(TIME_OF_LENGQUE);
	
	//�������͵�װ��
	//TODO�������
	
}

//�ڶ���������
void FenSui(void)
{
	//����λ���ط���ȥ
	Servo_Dangban_L_SetAngle(0);//TODO�ĽǶ�
	Servo_Dangban_R_SetAngle(0);
	
	//Ȼ���ٰѵ��彵��ȥ
	//TODO����������
	delay_ms(TIME_OF_DANGBAN_DOWN);
	
	//��ʼ����
	Motor_Fensui_SetSpeed(SPEED_OF_FENSUI);//TODO���ٶ�
	delay_ms(TIME_OF_FENSUI);//TODO����ʱ��
	
}

//���������ߵ��֣�װ����
void DianDianLe(void)
{
	//�ߵ���
	//TODO�������
	delay_ms(TIME_OF_DIANDIANLE);//TODO�ߵ���ʱ��
	
	//�ߵ��ֿ���
	Servo_Kaimen_SetAngle(600);//TODO�Ƕ�
	
	//��������
	Servo_Laji_SetAngle(600);
	
	
}

