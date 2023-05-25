/*
 * stm32f446_exti.c
 *
 *  Created on: May 22, 2023
 *      Author: moham
 */
#include "stm32f446_exti.h"

void (*GlobalCallBackINT[16])(void)={NULL};

void EXTI_Init(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,void (*APP)(void))
{
	GlobalCallBackINT[PinNumber]=APP;
	uint8_t RegisterNumber,PinValue,PortAsNumber;

	/*To determine which register from the SYSCFG EXTICR is the one we need*/
	RegisterNumber=PinNumber/4;

/*	To determine which 4 bits will we need*/
	PinValue=PinNumber%4;

/*	This functions transfers the GPIOx value from Pointer address to a NUMBER*/
	PortAsNumber=GPIO_PORT_TO_NUMBER(pGPIOx);

/*	Enable the Clock peripheral for the SYSCFG*/
	RCC_EnablePeripheral(APB2,APB2_SYSCFG);

/*	Set the GPIOx we will use in the EXTICR*/
	SYSCFG->EXTICR[RegisterNumber] &= ~(0xF<<PinValue*4);
	SYSCFG->EXTICR[RegisterNumber] |= (PortAsNumber<<PinValue*4);

/*	Set the PIN Number used by the EXTI*/
	EXTI->IMR |= (1<<PinNumber);

}

void EXTI_InterruptType(uint8_t PinNumber,uint8_t InterruptPhase){

	if(InterruptPhase==EXTI_MODE_IT_FE){
		/*Set the falling edged detector*/
		EXTI->FTSR |= (1<<PinNumber);
		EXTI->RTSR &= ~(1<<PinNumber);
	}
	else if(InterruptPhase==EXTI_MODE_IT_RE){
		/*Set the RISING edged detector*/
		EXTI->FTSR &= ~(1<<PinNumber);
		EXTI->RTSR |= (1<<PinNumber);
	}
	else if(InterruptPhase==EXTI_MODE_IT_FRE){
		/*Set the FALLING&RISING edged detector*/
		EXTI->FTSR |= (1<<PinNumber);
		EXTI->RTSR |= (1<<PinNumber);
	}
}
void EXTI_ClearPending(uint8_t PinNumber){

	/*Check if the pending flag is already set*/
	if(EXTI->PR & (1<<PinNumber)){
		EXTI->PR |= (1<<PinNumber);
	}
}

void EXTI_SetSofwareINT(uint8_t PinNumber){
	EXTI->SWIER |= (1<<PinNumber);
}
void EXTI0_IRQHandler(void){
	GlobalCallBackINT[0]();
}
void EXTI1_IRQHandler(void){

	GlobalCallBackINT[1]();
}

void EXTI2_IRQHandler(void){
	GlobalCallBackINT[2]();
}

void EXTI3_IRQHandler(void){
	GlobalCallBackINT[3]();
}

void EXTI4_IRQHandler(void){
	GlobalCallBackINT[4]();
}

void EXTI9_5_IRQHandler(void){

}

void EXTI15_10_IRQHandler(void){
	GlobalCallBackINT[13]();
}
