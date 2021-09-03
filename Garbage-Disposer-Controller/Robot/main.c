/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include <math.h>   
#include "key.h"
#include "sys.h"    //ϵͳ����
#include "delay.h"  //�����ʱ
#include "led.h"    //LED�ƿ���
#include "motor.h"    //ֱ��������ٿ���
#include "tim.h"      //��ʱ��
#include "servo.h"
#include "step.h"
#include "test.h"
#include "behaviour.h"

//��Ҫ��������

//void ROBOT_MoveCtl(void);  //�˶����ƺ���  

/**
  * @��  ��  ����������
  * @��  ��  ��
  * @����ֵ  ��
  */


int main(void)
{

//	Test_LED();
//	Test_Servo();
//	Test_Motor_PWM();

	
//	uint8_t cnt = 1;  //��ʱ������

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   //�����жϷ���

	JTAG_Set(JTAG_SWD_DISABLE);     
	JTAG_Set(SWD_ENABLE);      
	
	KEY_Init();
	Motor_Init(10);
	DELAY_Init();  
	Servo_Init();
	
//	LED_Init();
	
//    //������ʾ��Ϣ
//	LED_Blue_On();
//	LED_Green_On();
//	delay_ms(100);	
//	LED_Blue_Off();
//	LED_Green_Off();
//	delay_ms(300);

//	TIM6_Init(10000);
//	TIM6_Cmd(ENABLE);
	
	
//	//�̵Ƶ�������ʾ����
//	LED_Green_On();

	All_Init();

	//�����￪ʼ
	GuYeFenLi();
	FenSui();
	DianDianLe();
		
	while(1)
	{
		;
		
		
//		//100HZ����Ƶ��
//		if(TIM6_CheckIrqStatus())
//		{		
//			//50HZִ��Ƶ��
//			if(cnt%2 == 0)
//			{
//				;
//			}
//			//�������ۼ�
//			cnt++;
//		}
	}
}

