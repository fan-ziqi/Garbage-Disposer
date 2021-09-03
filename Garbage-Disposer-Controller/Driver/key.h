/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __KEY_H
#define __KEY_H

/* Includes ------------------------------------------------------------------*/	 
#include "stm32f10x.h"

void KEY_Init(void);  //°´¼ü³õÊ¼»¯

u8 KEY_Dangban_Down_L(void);
u8 KEY_Dangban_Down_R(void);
u8 KEY_Dangban_Up_L(void);
u8 KEY_Dangban_Up_R(void);

#endif 
