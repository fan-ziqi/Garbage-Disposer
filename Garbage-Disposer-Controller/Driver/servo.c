#include "servo.h" 
/**
  * @简  述  舵机初始化	
  * @参  数  无
  * @返回值  无
  */
  
void Servo_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	//GPIO功能时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);
	
	//配置IO口为复用功能-定时器通道
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度100MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//TIM时钟使能
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//定时器配置	PWM工作模式，频率50Hz,周期20ms  
	//占空比调节范围：0-1.5ms-2.5ms 0-1500-2500	初始化为1500
	TIM_TimeBaseStructure.TIM_Prescaler=72-1;  //定时器分频，分频后的频率为1M
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseStructure.TIM_Period=20000-1;   //自动重装载值
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	//PWM1 Mode configuration: Channel1 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 1500;	    //占空比初始化，90度
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	TIM_OC1Init(TIM2, &TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM2, &TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	TIM_OC3Init(TIM2, &TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM2, TIM_OCPreload_Enable);
	
	TIM_OC4Init(TIM2, &TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM2, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM2, ENABLE);

	//使能定时器
	TIM_Cmd(TIM2, ENABLE);	
	
	
}
  


/**
  * @简  述  舵机控制
  * @参  数  angle 舵机的角度，范围：0~1800，比例系数0.1,
             说明：部分舵机实际控制角度小于0~1800，请注意范围保护
  * @返回值  无
  */
void Servo_Dangban_L_SetAngle(uint16_t angle)
{
	if(angle > 1800)
		angle = 1800;
	
	angle = 1.111f*angle + 500;
	TIM_SetCompare1(TIM2,angle);
}

void Servo_Dangban_R_SetAngle(uint16_t angle)
{
	if(angle > 1800)
		angle = 1800;
	
	angle = 1.111f*angle + 500;
	TIM_SetCompare2(TIM2,angle);
}

void Servo_Laji_SetAngle(uint16_t angle)
{
	if(angle > 1800)
		angle = 1800;
	
	angle = 1.111f*angle + 500;
	TIM_SetCompare3(TIM2,angle);
}

void Servo_Kaimen_SetAngle(uint16_t angle)
{
	if(angle > 1800)
		angle = 1800;
	
	angle = 1.111f*angle + 500;
	TIM_SetCompare4(TIM2,angle);
}

