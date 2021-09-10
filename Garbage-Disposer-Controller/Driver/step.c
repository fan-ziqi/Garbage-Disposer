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
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//使能定时器3时钟
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //使能GPIO外设和AFIO复用功能模块时钟
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3部分重映射  TIM3_CH2->PB5    
 
   //设置该引脚为复用输出功能,输出TIM3 CH2的PWM脉冲波形	GPIOB.5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//初始化GPIO
	
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
 
   //初始化TIM3
	TIM_TimeBaseStructure.TIM_Period = 2000-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 36/freq_khz-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据TIM_TimeBaseInitStruct中指定的参数初始化TIMx的时间基数单位
	
	//初始化TIM3 Channel2 PWM模式	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = 0;	    //占空比初始化
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //根据T指定的参数初始化外设TIM3 OC2
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //使能TIM3在CCR2上的预装载寄存器
 
	TIM_Cmd(TIM3, ENABLE);  //使能TIM3
	
}

  
//void Step_Init(uint8_t freq_khz)
//{ 
//	
//	GPIO_InitTypeDef GPIO_InitStructure; 
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure; 

//	//定时器通道IO配置
//	//GPIO及复用功能时钟使能
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);	

//	//配置IO口为复用功能-定时器通道
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	//电机方向控制IO配置
//	//IO时钟使能
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

//	//电机A方向控制IO
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOD, &GPIO_InitStructure);

//	//定时器配置
//	//参数过滤
//	if(freq_khz == 0)
//	freq_khz = 1;
//	if(freq_khz > 20)
//	freq_khz = 20;
//	 
//	//TIM时钟使能
//	RCC_APB2PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

//	//Time base configuration
//	TIM_TimeBaseStructure.TIM_Period = 2000-1;
//	TIM_TimeBaseStructure.TIM_Prescaler = 36/freq_khz-1;
//	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//
//	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
//	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

//	//PWM1 Mode configuration: Channel1 
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_Pulse = 0;	    //占空比初始化
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
//	
//	TIM_OC1Init(TIM4, &TIM_OCInitStructure);
//	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

//	//PWM1 Mode configuration: Channel2
//	TIM_OC2Init(TIM4, &TIM_OCInitStructure);
//	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

//	//PWM1 Mode configuration: Channel3
//	TIM_OC3Init(TIM4, &TIM_OCInitStructure);
//	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

//	//PWM1 Mode configuration: Channel4
//	TIM_OC4Init(TIM4, &TIM_OCInitStructure);
//	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

//	TIM_ARRPreloadConfig(TIM4, ENABLE);

//	//TIM enable counter
//	TIM_Cmd(TIM4, ENABLE);   

//}

void Step_Fenli_L_Move(u8 dir)
{
	if(dir == ZHENG)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_0);
		TIM_SetCompare1(TIM3,1000);
	}
		
	else if(dir == FAN)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_0);
		TIM_SetCompare1(TIM3,1000);
	}
	else if(dir == TING)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_0);
		TIM_SetCompare1(TIM3,0);
	}
}

void Step_Fenli_R_Move(u8 dir)
{
	if(dir == ZHENG)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_1);
		TIM_SetCompare2(TIM3,1000);
	}
		
	else if(dir == FAN)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_1);
		TIM_SetCompare2(TIM3,1000);
	}
	else if(dir == TING)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_1);
		TIM_SetCompare2(TIM3,0);
	}
}

void Step_Dian_Move(u8 dir)
{
	if(dir == ZHENG)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		TIM_SetCompare3(TIM3,1000);
	}
		
	else if(dir == FAN)
	{
		GPIO_ResetBits(GPIOD, GPIO_Pin_2);
		TIM_SetCompare3(TIM3,1000);
	}
	else if(dir == TING)
	{
		GPIO_SetBits(GPIOD, GPIO_Pin_2);
		TIM_SetCompare3(TIM3,0);
	}
}
