/*
 * stm32f446_systick.c
 *
 *  Created on: May 25, 2023
 *      Author: moham
 */


#include "stm32f446_systick.h"

void SysTick_Init(uint8_t ClockSource,uint8_t EnOrDis,uint8_t SyncOrAsync){

	if(ClockSource == Systick_ClockSource_AHB){
		SysTick->CTRL |= (1<<2);
	}
	else if(ClockSource == Systick_ClockSource_AHB_8){
		SysTick->CTRL &= ~(1<<2);
	}

	if(EnOrDis==ENABLE){
	SysTick->CTRL |= (1<<0);
	}
	else if(EnOrDis==DISABLE){
	SysTick->CTRL &= ~(1<<0);
	}

	if(SyncOrAsync==Systick_Sync){
		SysTick->CTRL &= ~(1<<1);
	}
	else if(SyncOrAsync==Systick_Async){
		SysTick->CTRL |= (1<<1);
	}
}

void Systick_EnterValue(uint32_t Count){

	SysTick->LOAD = Count;

}

void Systick_ResetCounter(void){
	SysTick->VAL =0xFF;
}

uint32_t Systick_GetCurrentCount(void){

	uint32_t current;
	current=SysTick->VAL;
	return current;

}

void Systick_TimerAsync(uint32_t Timer){
	/*Maximum 2087 MS*/
	SysTick->LOAD =(2000*Timer)-1;
	Systick_ResetCounter();
}

void Systick_TimerSync(uint32_t Timer){
	SysTick->LOAD =(2000*Timer)-1;
	Systick_ResetCounter();

	while(!((SysTick->CTRL >>16) & (0x1)));

}
