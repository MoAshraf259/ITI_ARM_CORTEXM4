/*
 * stm32f446_exti.c
 *
 *  Created on: May 22, 2023
 *      Author: moham
 */
#include "stm32f446_exti.h"

void EXTI_Init(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t InterruptPhase)
{
	if(InterruptPhase==EXTI_MODE_IT_FE){
		EXTI->FTSR |= (1<<PinNumber);
		EXTI->RTSR &= ~(1<<PinNumber);
	}
	else if(InterruptPhase==EXTI_MODE_IT_RE){
		EXTI->FTSR &= ~(1<<PinNumber);
		EXTI->RTSR |= (1<<PinNumber);
	}
	else if(InterruptPhase==EXTI_MODE_IT_FRE){
		EXTI->FTSR |= (1<<PinNumber);
		EXTI->RTSR |= (1<<PinNumber);
	}

	uint8_t RegisterNumber,PinValue,PortAsNumber;

	RegisterNumber=PinNumber/4;
	PinValue=PinNumber%4;

	PortAsNumber=GPIO_PORT_TO_NUMBER(pGPIOx);
	RCC_EnablePeripheral(APB2,APB2_SYSCFG);
	SYSCFG->EXTICR[RegisterNumber] |= (PortAsNumber<<PinValue*4);

	EXTI->IMR |= (1<<PinNumber);

}

void EXTI_ClearPending(uint8_t PinNumber){
	if(EXTI->PR & (1<<PinNumber)){
		EXTI->PR |= (1<<PinNumber);
	}
}
