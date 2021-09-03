/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STEP_H
#define __STEP_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

enum
{
	ZHENG = 0,
	FAN,
	TING
};

void Step_Init(uint8_t freq_khz);

void Step_Fenli_L_Move(u8 dir);
void Step_Fenli_R_Move(u8 dir);
void Step_Dian_Move(u8 dir);

#endif
