#include "test.h"
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



/******************************************************************************
LED_Green����0.5S,LED_Blue����0.5S,LED��ת,�������
*******************************************************************************/
void Test_LED(void)
{
	
	//�����ж����ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);    

	//JTAG������
	JTAG_Set(JTAG_SWD_DISABLE);  //�ر�JTAG�ӿ� 
	JTAG_Set(SWD_ENABLE);  //��SWD�ӿ� �������������SWD�ӿڵ��� 
	
	//�����ʱ��ʼ��
	DELAY_Init(); 	
	LED_Init();  //LED��ʼ��
	
	//LED_Green����0.5S
	LED_Green_On();
	delay_ms(500);
	LED_Green_Off();               
	delay_ms(500);
	
	//LED_Blue����0.5S
	LED_Blue_On();
	delay_ms(500);
	LED_Blue_Off();
	delay_ms(500);
	
	LED_Blue_On();
	
	while (1)
	{	
		//LED��ת
		LED_Green_Toggle();
		LED_Blue_Toggle();
	}
}


/******************************************************************************
����8·���60�ȡ�90�ȡ�120�ȼ���˶�
*******************************************************************************/
void Test_Servo(void)
{
	//�����ж����ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	
	//JTAG������
	JTAG_Set(JTAG_SWD_DISABLE);  //�ر�JTAG�ӿ� 
	JTAG_Set(SWD_ENABLE);  //��SWD�ӿ� �������������SWD�ӿڵ��� 		
	
	//�����ʱ��ʼ��
	DELAY_Init();
	LED_Init();
	
	//��ʼ��
	Servo_Init();

	while (1) 
	{		
//		printf("*60��...... \r\n");		
		Servo_Dangban_L_SetAngle(600);
		Servo_Dangban_R_SetAngle(600);
		Servo_Laji_SetAngle     (600);
		Servo_Kaimen_SetAngle   (600);
		delay_ms(1000);
		
//		printf("*90��...... \r\n");
		Servo_Dangban_L_SetAngle(900);
		Servo_Dangban_R_SetAngle(900);
		Servo_Laji_SetAngle     (900);
		Servo_Kaimen_SetAngle   (900);
		delay_ms(1000);
		
//		printf("*120��...... \r\n");
		Servo_Dangban_L_SetAngle(1200);
		Servo_Dangban_R_SetAngle(1200);
		Servo_Laji_SetAngle     (1200);
		Servo_Kaimen_SetAngle   (1200);
		delay_ms(1000);
	}
}		



/******************************************************************************
����4·ֱ�����PWM����,������ת�ͱ��ٷ�ת��������
*******************************************************************************/
void Test_Motor_PWM(void)
{
	int temp;
	
	//�����ж����ȼ�����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	
	//JTAG������
	JTAG_Set(JTAG_SWD_DISABLE);  //�ر�JTAG�ӿ� 
	JTAG_Set(SWD_ENABLE);  //��SWD�ӿ� �������������SWD�ӿڵ��� 		
	
	//�����ʱ��ʼ��
	DELAY_Init(); 	
	LED_Init();  
	
	//��ʼ��
	Motor_Init(10);  //���õ������PWMƵ��Ϊ10K
	
	for(temp=0; temp>=-2000; temp--)
	{
		Motor_Dangban_L_SetSpeed(temp); 
		Motor_Dangban_R_SetSpeed(temp); 
		Motor_Fensui_SetSpeed(temp); 
//		MOTOR4_SetSpeed(temp); 
		delay_ms(5);
	}

	while (1) 
	{	
		//���Ƶ��ת��
		for(temp=-2000; temp<=2000; temp++)
		{
			Motor_Dangban_L_SetSpeed(temp); 
			Motor_Dangban_R_SetSpeed(temp); 
			Motor_Fensui_SetSpeed(temp); 
//			MOTOR4_SetSpeed(temp); 
			delay_ms(5);
		}
		for(temp=2000; temp>=-2000; temp--)
		{
			Motor_Dangban_L_SetSpeed(temp); 
			Motor_Dangban_R_SetSpeed(temp); 
			Motor_Fensui_SetSpeed(temp); 
//			MOTOR4_SetSpeed(temp); 
			delay_ms(5);
		}
	}
}	

