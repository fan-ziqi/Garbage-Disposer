/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/	 
#include "stm32f10x.h"


#define KEY4 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_6) //PC6
#define KEY3 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_7) //PC7 
#define KEY2 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8) //PC8
#define KEY1 GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_9) //PC9

typedef enum
{
	KEY_DOWN=1,
	KEY_UP,
	KEY_DOWNUP,
} KEY_STATE;

void KEY_Init(void);  //按键初始化
void KEY_Scan(void);  //按键扫描

u8 KEY_Dangban_Down_L(void);
u8 KEY_Dangban_Down_R(void);
u8 KEY_Dangban_Up_L(void);
u8 KEY_Dangban_Up_R(void);

#endif 
