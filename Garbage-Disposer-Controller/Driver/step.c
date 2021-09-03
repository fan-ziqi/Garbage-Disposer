#include "step.h"

/**
  * @简  述  电机PWM控制初始化	
  * @参  数  freq_khz:PWM输出频率，范围1~20,单位KHz
  * @返回值  无
  */
void Step_Init(uint8_t freq_khz)
{ 
	
	GPIO_InitTypeDef GPIO_InitStructure; 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 

	//定时器通道IO配置
	//GPIO及复用功能时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);	

	//配置IO口为复用功能-定时器通道
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	//电机方向控制IO配置
	//IO时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

	//电机A方向控制IO
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	//定时器配置
	//参数过滤
	if(freq_khz == 0)
	freq_khz = 1;
	if(freq_khz > 20)
	freq_khz = 20;
	 
	//TIM时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	//Time base configuration
	TIM_TimeBaseStructure.TIM_Period = 2000-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 36/freq_khz-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	//PWM1 Mode configuration: Channel1 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;	    //占空比初始化
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	//PWM1 Mode configuration: Channel2
	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	//PWM1 Mode configuration: Channel3
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	//PWM1 Mode configuration: Channel4
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM4, ENABLE);

	//TIM enable counter
	TIM_Cmd(TIM4, ENABLE);   

	//使能MOE位
	TIM_CtrlPWMOutputs(TIM4,ENABLE);	
}

void Step_Fenli_L_Move(u8 dir)
{
	if(dir == ZHENG)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_0);
		TIM_SetCompare1(TIM4,1000);
	}
		
	else if(dir == FAN)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_0);
		TIM_SetCompare1(TIM4,1000);
	}
	else if(dir == TING)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_0);
		TIM_SetCompare1(TIM4,0);
	}
}

void Step_Fenli_R_Move(u8 dir)
{
	if(dir == ZHENG)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_1);
		TIM_SetCompare2(TIM4,1000);
	}
		
	else if(dir == FAN)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_1);
		TIM_SetCompare2(TIM4,1000);
	}
	else if(dir == TING)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_1);
		TIM_SetCompare2(TIM4,0);
	}
}

void Step_Dian_Move(u8 dir)
{
	if(dir == ZHENG)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		TIM_SetCompare3(TIM4,1000);
	}
		
	else if(dir == FAN)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
		TIM_SetCompare3(TIM4,1000);
	}
	else if(dir == TING)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		TIM_SetCompare3(TIM4,0);
	}
}
