#include "step.h"

/**
  * @��  ��  ���PWM���Ƴ�ʼ��	
  * @��  ��  freq_khz:PWM���Ƶ�ʣ���Χ1~20,��λKHz
  * @����ֵ  ��
  */
  
void Step_Init(uint8_t freq_khz)
{  
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	//ʹ�ܶ�ʱ��3ʱ��
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB  | RCC_APB2Periph_AFIO, ENABLE);  //ʹ��GPIO�����AFIO���ù���ģ��ʱ��
	
	GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3, ENABLE); //Timer3������ӳ��  TIM3_CH2->PB5    
 
   //���ø�����Ϊ�����������,���TIM3 CH2��PWM���岨��	GPIOB.5
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //�����������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIO
	
	//����������IO����
	//IOʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

	//���A�������IO
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	//��ʱ������
	//��������
	if(freq_khz == 0)
	freq_khz = 1;
	if(freq_khz > 20)
	freq_khz = 20;
 
   //��ʼ��TIM3
	TIM_TimeBaseStructure.TIM_Period = 2000-1;
	TIM_TimeBaseStructure.TIM_Prescaler = 36/freq_khz-1;
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;//
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����TIM_TimeBaseInitStruct��ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
	
	//��ʼ��TIM3 Channel2 PWMģʽ	 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ2
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_Pulse = 0;	    //ռ�ձȳ�ʼ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //�������:TIM����Ƚϼ��Ը�
	
	TIM_OC1Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC2Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC3Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
	
	TIM_OC4Init(TIM3, &TIM_OCInitStructure);  //����Tָ���Ĳ�����ʼ������TIM3 OC2
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);  //ʹ��TIM3��CCR2�ϵ�Ԥװ�ؼĴ���
 
	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIM3
	
}

  
//void Step_Init(uint8_t freq_khz)
//{ 
//	
//	GPIO_InitTypeDef GPIO_InitStructure; 
//	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
//	TIM_OCInitTypeDef  TIM_OCInitStructure; 

//	//��ʱ��ͨ��IO����
//	//GPIO�����ù���ʱ��ʹ��
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);	

//	//����IO��Ϊ���ù���-��ʱ��ͨ��
//	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOB, &GPIO_InitStructure);

//	//����������IO����
//	//IOʱ��ʹ��
//	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

//	//���A�������IO
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//	GPIO_Init(GPIOD, &GPIO_InitStructure);

//	//��ʱ������
//	//��������
//	if(freq_khz == 0)
//	freq_khz = 1;
//	if(freq_khz > 20)
//	freq_khz = 20;
//	 
//	//TIMʱ��ʹ��
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
//	TIM_OCInitStructure.TIM_Pulse = 0;	    //ռ�ձȳ�ʼ��
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
