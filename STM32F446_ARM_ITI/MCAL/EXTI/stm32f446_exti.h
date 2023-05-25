/*
 * stm32f446_exti.h
 *
 *  Created on: May 22, 2023
 *      Author: moham
 */

#ifndef EXTI_STM32F446_EXTI_H_
#define EXTI_STM32F446_EXTI_H_
#include "stm32f446.h"


#define EXTI_MODE_IT_FE			1
#define EXTI_MODE_IT_RE			2
#define EXTI_MODE_IT_FRE		3


void EXTI_Init(GPIO_RegDef_t *pGPIOx , uint8_t PinNumber , void (*APP)(void));
void EXTI_InterruptType(uint8_t PinNumber,uint8_t InterruptPhase);
void EXTI_ClearPending(uint8_t PinNumber);
void EXTI_SetSofwareINT(uint8_t PinNumber);

#endif /* EXTI_STM32F446_EXTI_H_ */
