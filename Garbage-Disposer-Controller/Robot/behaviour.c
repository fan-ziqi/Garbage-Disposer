#include "behaviour.h"
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
#include "step.h"

#define SPEED_OF_DANGBAN 1000
#define TIME_OF_LENGQUE 10000
#define TIME_OF_YOUSHENG 1000
#define TIME_OF_DANGBAN_DOWN 5000
#define SPEED_OF_FENSUI 1000
#define TIME_OF_FENSUI 20000
#define TIME_OF_DIANDIANLE 20000

//整体初始化
void All_Init(void)
{
	//把限位开关支起来
	Servo_Dangban_L_SetAngle(1000);//TODO改角度
	Servo_Dangban_R_SetAngle(1000);
	
	//然后再把挡板降下来
	while( (!KEY_Dangban_Down_L()) && (!KEY_Dangban_Down_R()) )
    {
		Motor_Dangban_L_SetSpeed(-SPEED_OF_DANGBAN);
		Motor_Dangban_R_SetSpeed(-SPEED_OF_DANGBAN);
		//TODO挡板往下走
	}
	
	//颠颠乐关门
	Servo_Kaimen_SetAngle(600);
	
	//封上垃圾袋
	Servo_Laji_SetAngle(600);
	
	//其他的咋办？
}

//第一步，固液分离，水油分离
void GuYeFenLi(void)
{
	//固液分离
	//把挡板升起来
	while( (!KEY_Dangban_Up_L()) && (!KEY_Dangban_Up_R()) )
    {
		Motor_Dangban_L_SetSpeed(SPEED_OF_DANGBAN);
		Motor_Dangban_R_SetSpeed(SPEED_OF_DANGBAN);
	}
	
	//开启制冷片和风扇
	//TODO
	delay_ms(TIME_OF_LENGQUE);
	
	//升起处理油的装置
	Step_Fenli_L_Move(ZHENG);
	Step_Fenli_R_Move(ZHENG);
	delay_ms(TIME_OF_YOUSHENG);
	Step_Fenli_L_Move(TING);
	Step_Fenli_R_Move(TING);
}

//第二步，粉碎
void FenSui(void)
{
	//把限位开关放下去
	Servo_Dangban_L_SetAngle(0);//TODO改角度
	Servo_Dangban_R_SetAngle(0);
	
	//然后再把挡板降下去
	Motor_Dangban_L_SetSpeed(SPEED_OF_DANGBAN);
	Motor_Dangban_R_SetSpeed(SPEED_OF_DANGBAN);
	delay_ms(TIME_OF_DANGBAN_DOWN);
	
	//开始粉碎
	Motor_Fensui_SetSpeed(SPEED_OF_FENSUI);//TODO改速度
	delay_ms(TIME_OF_FENSUI);//TODO粉碎时间
	
}

//第三步，颠颠乐，装垃圾
void DianDianLe(void)
{
	//颠颠乐
	for(int i=0;i<=10;i++)
	{
		Step_Dian_Move(ZHENG);
		delay_ms(TIME_OF_DIANDIANLE);//TODO颠颠乐时间
		Step_Dian_Move(FAN);
		delay_ms(TIME_OF_DIANDIANLE);//TODO颠颠乐时间
	}
	Step_Dian_Move(TING);
	
	//颠颠乐开门
	Servo_Kaimen_SetAngle(600);//TODO角度
	
	//打开垃圾袋
	Servo_Laji_SetAngle(600);
	
	
}

