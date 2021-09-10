#include "servo.h" 
/**
  * @��  ��  �����ʼ��	
  * @��  ��  ��
  * @����ֵ  ��
  */
  
void Servo_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure; 	
	
	//GPIO����ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA| RCC_APB2Periph_AFIO, ENABLE);
	
	//����IO��Ϊ���ù���-��ʱ��ͨ��
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;   //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//�ٶ�100MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//TIMʱ��ʹ��
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	//��ʱ������	PWM����ģʽ��Ƶ��50Hz,����20ms  
	//ռ�ձȵ��ڷ�Χ��0-1.5ms-2.5ms 0-1500-2500	��ʼ��Ϊ1500
	TIM_TimeBaseStructure.TIM_Prescaler=72-1;  //��ʱ����Ƶ����Ƶ���Ƶ��Ϊ1M
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseStructure.TIM_Period=20000-1;   //�Զ���װ��ֵ
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
	
	//PWM1 Mode configuration: Channel1 
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 1500;	    //ռ�ձȳ�ʼ����90��
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

	//ʹ�ܶ�ʱ��
	TIM_Cmd(TIM2, ENABLE);	
	
	
}
  


/**
  * @��  ��  �������
  * @��  ��  angle ����ĽǶȣ���Χ��0~1800������ϵ��0.1,
             ˵�������ֶ��ʵ�ʿ��ƽǶ�С��0~1800����ע�ⷶΧ����
  * @����ֵ  ��
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

