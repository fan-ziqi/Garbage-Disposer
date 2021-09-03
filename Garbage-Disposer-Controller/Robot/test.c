#include "test.h"
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <stdio.h>

#include "sys.h"    //系统设置
#include "delay.h"  //软件延时
#include "led.h"    //LED灯控制
#include "key.h"    //按键检测 
#include "motor.h"    //直流电机调速控制
#include "servo.h"    //舵机控制
#include "tim.h"      //定时器



/******************************************************************************
LED_Green点亮0.5S,LED_Blue点亮0.5S,LED反转,串口输出
*******************************************************************************/
void Test_LED(void)
{
	
	//设置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);    

	//JTAG口设置
	JTAG_Set(JTAG_SWD_DISABLE);  //关闭JTAG接口 
	JTAG_Set(SWD_ENABLE);  //打开SWD接口 可以利用主板的SWD接口调试 
	
	//软件延时初始化
	DELAY_Init(); 	
	LED_Init();  //LED初始化
	
	//LED_Green点亮0.5S
	LED_Green_On();
	delay_ms(500);
	LED_Green_Off();               
	delay_ms(500);
	
	//LED_Blue点亮0.5S
	LED_Blue_On();
	delay_ms(500);
	LED_Blue_Off();
	delay_ms(500);
	
	LED_Blue_On();
	
	while (1)
	{	
		//LED反转
		LED_Green_Toggle();
		LED_Blue_Toggle();
	}
}


/******************************************************************************
控制8路舵机60度、90度、120度间隔运动
*******************************************************************************/
void Test_Servo(void)
{
	//设置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	
	//JTAG口设置
	JTAG_Set(JTAG_SWD_DISABLE);  //关闭JTAG接口 
	JTAG_Set(SWD_ENABLE);  //打开SWD接口 可以利用主板的SWD接口调试 		
	
	//软件延时初始化
	DELAY_Init();
	LED_Init();
	
	//初始化
	Servo_Init();

	while (1) 
	{		
//		printf("*60度...... \r\n");		
		Servo_Dangban_L_SetAngle(600);
		Servo_Dangban_R_SetAngle(600);
		Servo_Laji_SetAngle     (600);
		Servo_Kaimen_SetAngle   (600);
		delay_ms(1000);
		
//		printf("*90度...... \r\n");
		Servo_Dangban_L_SetAngle(900);
		Servo_Dangban_R_SetAngle(900);
		Servo_Laji_SetAngle     (900);
		Servo_Kaimen_SetAngle   (900);
		delay_ms(1000);
		
//		printf("*120度...... \r\n");
		Servo_Dangban_L_SetAngle(1200);
		Servo_Dangban_R_SetAngle(1200);
		Servo_Laji_SetAngle     (1200);
		Servo_Kaimen_SetAngle   (1200);
		delay_ms(1000);
	}
}		



/******************************************************************************
控制4路直流电机PWM调速,变速正转和变速反转交替运行
*******************************************************************************/
void Test_Motor_PWM(void)
{
	int temp;
	
	//设置中断优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  
	
	//JTAG口设置
	JTAG_Set(JTAG_SWD_DISABLE);  //关闭JTAG接口 
	JTAG_Set(SWD_ENABLE);  //打开SWD接口 可以利用主板的SWD接口调试 		
	
	//软件延时初始化
	DELAY_Init(); 	
	LED_Init();  
	
	//初始化
	Motor_Init(10);  //设置电机控制PWM频率为10K
	
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
		//控制电机转动
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

