/*
 * stm32f446_systick.h
 *
 *  Created on: May 25, 2023
 *      Author: moham
 */

#ifndef SYSTICK_STM32F446_SYSTICK_H_
#define SYSTICK_STM32F446_SYSTICK_H_

#include "stm32f446.h"

#define Systick_ClockSource_AHB			1
#define Systick_ClockSource_AHB_8		2

#define Systick_Sync		0
#define Systick_Async		1


void Systick_TimerSync(uint32_t Timer);
void Systick_TimerAsync(uint32_t Timer,void (*ApplicationCallBack)(void));
uint32_t Systick_GetCurrentCount(void);

void Systick_EnterValue(uint32_t Count);
void SysTick_Init(uint8_t ClockSource,uint8_t SyncOrAsync,uint8_t EnOrDis);
#endif /* SYSTICK_STM32F446_SYSTICK_H_ */
