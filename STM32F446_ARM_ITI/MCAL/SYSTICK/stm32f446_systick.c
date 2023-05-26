/*
 * stm32f446_systick.c
 *
 *  Created on: May 25, 2023
 *      Author: moham
 */


#include "stm32f446_systick.h"

void (*GlobalCallBack)(void)=NULL;
static void Systick_DisableInterrupt(void);
static void Systick_ResetCounter(void);

void SysTick_Init(uint8_t ClockSource,uint8_t SyncOrAsync,uint8_t EnOrDis){

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

	Systick_ResetCounter();
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

void Systick_TimerAsync(uint32_t Timer,void (*ApplicationCallBack)(void)){

	Systick_ResetCounter();
	GlobalCallBack=ApplicationCallBack;

	SysTick->LOAD =(2000*Timer)-1;
	Systick_ResetCounter();
}

void Systick_TimerSync(uint32_t Timer){

	Systick_DisableInterrupt();

	Systick_ResetCounter();

	SysTick->LOAD =(2000*Timer)-1;

	Systick_ResetCounter();

	while(!((SysTick->CTRL >>16) & (0x1)));

}

static void Systick_DisableInterrupt(void){
	SysTick->CTRL &= ~(1<<1);
}
void SysTick_Handler(void){
	GlobalCallBack();
}
