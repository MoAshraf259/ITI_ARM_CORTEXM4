/*
 * stm32_f446_nvic.c
 *
 *  Created on: May 22, 2023
 *      Author: Mohamed Ashraf
 */


#include "stm32f446_nvic.h"

/*This array defines the number of groups can be used "Configurations"*/
uint8_t PRIGROUP[5]={7,6,5,4,0};
uint32_t pass=0x05FA;

void NVIC_Init(uint8_t Num_Of_GroupBits)
{
	//The pass used to access the REGISTER  & Num_Of_GroupBits is the Shifted until met
	RCB_AIRCR = ((pass<<16) |( PRIGROUP[Num_Of_GroupBits]<<8));
}


void NVIC_ControlPeripheral(uint8_t IRQ,uint8_t EnOrDis){
	uint8_t temp1,temp2;


	temp1=IRQ/32;
	temp2=IRQ%32;

	if(EnOrDis==ENABLE){
		NVIC->ISER[temp1] |= (1<<temp2);
	}
	else{
		NVIC->ICER[temp1] |= (1<<temp2);
	}
}

void NVIC_ControlPendingFlag(uint8_t IRQ,uint8_t EnOrDis){
	uint8_t temp1,temp2;

	temp1=IRQ/32;
	temp2=IRQ%32;

	if(EnOrDis==ENABLE){
		NVIC->ISPR[temp1] |= (1<<temp2);
	}
	else{
		NVIC->ICPR[temp1] |= (1<<temp2);
	}
}
uint8_t NVIC_ReadActive(uint8_t IRQ)
{
	uint8_t temp1,temp2;

	temp1=IRQ/32;
	temp2=IRQ%32;

	uint8_t temp = ( (NVIC->IABR[temp1]>>temp2) & (0x1) );

	return temp;
}



void NVIC_SetPriority(uint8_t IRQ,uint8_t GroupPriority,uint8_t SubPriority,uint8_t NumOfGroupBits)
{

	uint8_t temp1,temp2,shift_value;

	temp1=IRQ/4;
	temp2=IRQ%4;

	shift_value =(temp2*4) +(8-NumOfGroupBits);

	NVIC->IPR[temp1] |= (GroupPriority<<shift_value);
	NVIC->IPR[temp1] |= (SubPriority<<( (temp2*4) + 4 ));

}

