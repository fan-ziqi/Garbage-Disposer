/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>
#include <math.h>   
#include "key.h"
#include "sys.h"    //系统设置
#include "delay.h"  //软件延时
#include "led.h"    //LED灯控制
#include "motor.h"    //直流电机调速控制
#include "tim.h"      //定时器
#include "servo.h"
#include "step.h"
#include "test.h"
#include "behaviour.h"

//主要函数声明

//void ROBOT_MoveCtl(void);  //运动控制函数  

/**
  * @简  述  程序主函数
  * @参  数  无
  * @返回值  无
  */


int main(void)
{

//	Test_LED();
//	Test_Servo();
//	Test_Motor_PWM();

	
//	uint8_t cnt = 1;  //定时器计数

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   //设置中断分组

	JTAG_Set(JTAG_SWD_DISABLE);     
	JTAG_Set(SWD_ENABLE);      
	
	KEY_Init();
	Motor_Init(10);
	DELAY_Init();  
	Servo_Init();
	
//	LED_Init();
	
//    //开机提示信息
//	LED_Blue_On();
//	LED_Green_On();
//	delay_ms(100);	
//	LED_Blue_Off();
//	LED_Green_Off();
//	delay_ms(300);

//	TIM6_Init(10000);
//	TIM6_Cmd(ENABLE);
	
	
//	//绿灯点亮，提示运行
//	LED_Green_On();

	All_Init();

	//从这里开始
	GuYeFenLi();
	FenSui();
	DianDianLe();
		
	while(1)
	{
		;
		
		
//		//100HZ控制频率
//		if(TIM6_CheckIrqStatus())
//		{		
//			//50HZ执行频率
//			if(cnt%2 == 0)
//			{
//				;
//			}
//			//计数器累加
//			cnt++;
//		}
	}
}

