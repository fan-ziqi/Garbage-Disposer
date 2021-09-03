/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include <math.h>   

#include "sys.h"    //ϵͳ����
#include "delay.h"  //������ʱ
#include "led.h"    //LED�ƿ���
#include "motor.h"    //ֱ��������ٿ���
#include "tim.h"      //��ʱ��

#include "test.h"


//��Ҫ��������

void ROBOT_MoveCtl(void);  //�˶����ƺ���  

/**
  * @��  ��  ����������
  * @��  ��  ��
  * @����ֵ  ��
  */


int main(void)
{

//	Test_LED();
//	Test_KEY();
//	Test_Servo();
//	Test_Motor_PWM();

	
	uint8_t cnt = 1;  //��ʱ������

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   //�����жϷ���

	//�����˳�ʼ��
	MOTOR_Init(10);
	DELAY_Init();  
	JTAG_Set(JTAG_SWD_DISABLE);     
	JTAG_Set(SWD_ENABLE);          
	LED_Init();
	
    //������ʾ��Ϣ
	LED_Blue_On();
	LED_Green_On();
	delay_ms(100);	
	LED_Blue_Off();
	LED_Green_Off();
	delay_ms(300);

	TIM6_Init(10000);
	TIM6_Cmd(ENABLE);
	
	
	//�̵Ƶ�������ʾ����
	LED_Green_On();

	while(1)
	{
		//100HZ����Ƶ��
		if(TIM6_CheckIrqStatus())
		{		

			
			//50HZִ��Ƶ��
			if(cnt%2 == 0)
			{
				
				//�˶�����
				
			}
			
			//�������ۼ�
			cnt++;
		}
	}
}
