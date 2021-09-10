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
#include "step.h"

#define SPEED_OF_DANGBAN 1000
#define TIME_OF_LENGQUE 10000
#define TIME_OF_YOUSHENG 1000
#define TIME_OF_DANGBAN_DOWN 5000
#define SPEED_OF_FENSUI 1000
#define TIME_OF_FENSUI 20000
#define TIME_OF_DIANDIANLE 20000

//�����ʼ��
void All_Init(void)
{
	//����λ����֧����
	Servo_Dangban_L_SetAngle(1000);//TODO�ĽǶ�
	Servo_Dangban_R_SetAngle(1000);
	
	//Ȼ���ٰѵ��彵����
	while( (!KEY_Dangban_Down_L()) && (!KEY_Dangban_Down_R()) )
    {
		Motor_Dangban_L_SetSpeed(-SPEED_OF_DANGBAN);
		Motor_Dangban_R_SetSpeed(-SPEED_OF_DANGBAN);
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
	while( (!KEY_Dangban_Up_L()) && (!KEY_Dangban_Up_R()) )
    {
		Motor_Dangban_L_SetSpeed(SPEED_OF_DANGBAN);
		Motor_Dangban_R_SetSpeed(SPEED_OF_DANGBAN);
	}
	
	//��������Ƭ�ͷ���
	//TODO
	delay_ms(TIME_OF_LENGQUE);
	
	//�������͵�װ��
	Step_Fenli_L_Move(ZHENG);
	Step_Fenli_R_Move(ZHENG);
	delay_ms(TIME_OF_YOUSHENG);
	Step_Fenli_L_Move(TING);
	Step_Fenli_R_Move(TING);
}

//�ڶ���������
void FenSui(void)
{
	//����λ���ط���ȥ
	Servo_Dangban_L_SetAngle(0);//TODO�ĽǶ�
	Servo_Dangban_R_SetAngle(0);
	
	//Ȼ���ٰѵ��彵��ȥ
	Motor_Dangban_L_SetSpeed(SPEED_OF_DANGBAN);
	Motor_Dangban_R_SetSpeed(SPEED_OF_DANGBAN);
	delay_ms(TIME_OF_DANGBAN_DOWN);
	
	//��ʼ����
	Motor_Fensui_SetSpeed(SPEED_OF_FENSUI);//TODO���ٶ�
	delay_ms(TIME_OF_FENSUI);//TODO����ʱ��
	
}

//���������ߵ��֣�װ����
void DianDianLe(void)
{
	//�ߵ���
	for(int i=0;i<=10;i++)
	{
		Step_Dian_Move(ZHENG);
		delay_ms(TIME_OF_DIANDIANLE);//TODO�ߵ���ʱ��
		Step_Dian_Move(FAN);
		delay_ms(TIME_OF_DIANDIANLE);//TODO�ߵ���ʱ��
	}
	Step_Dian_Move(TING);
	
	//�ߵ��ֿ���
	Servo_Kaimen_SetAngle(600);//TODO�Ƕ�
	
	//��������
	Servo_Laji_SetAngle(600);
	
	
}

