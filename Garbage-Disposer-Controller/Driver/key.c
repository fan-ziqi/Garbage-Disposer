#include "key.h"
#include "delay.h"
#include "sys.h"


/**
  * @简  述  KEY 按键初始化
  * @参  数  无
  * @返回值  无
  */
void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	//使配置GPIO
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF,ENABLE);
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //TODO这里需要改一下，浮空输入或者上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 	GPIO_Init(GPIOF, &GPIO_InitStructure);


	
}


/**
@func: 触点开关检测
@param: None
@return: X轴触点开关按下时返回1，否则返回0
@brief: None
*/
u8 KEY_Dangban_Down_L(void)
{
    if ( GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_0) == 0)
    {
        return 1;
    }
    return 0;
}

u8 KEY_Dangban_Down_R(void)
{
    if ( GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_1) == 0)
    {
        return 1;
    }
    return 0;
}

u8 KEY_Dangban_Up_L(void)
{
    if ( GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_2) == 0)
    {
        return 1;
    }
    return 0;
}

u8 KEY_Dangban_Up_R(void)
{
    if ( GPIO_ReadInputDataBit(GPIOF, GPIO_Pin_3) == 0)
    {
        return 1;
    }
    return 0;
}
