/*
 * stm32f446_nvic.h
 *
 *  Created on: May 22, 2023
 *      Author: Mohamed Ashraf
 */

#ifndef NVIC_STM32F446_NVIC_H_
#define NVIC_STM32F446_NVIC_H_
#include "stm32f446.h"

void NVIC_Init(uint8_t Num_Of_GroupBits);
void NVIC_ControlPeripheral(uint8_t IRQ,uint8_t EnOrDis);
void NVIC_SetPriority(uint8_t IRQ,uint8_t GroupPriority,uint8_t SubPriority,uint8_t NumOfGroupBits);
void NVIC_ControlPendingFlag(uint8_t IRQ,uint8_t EnOrDis);

#endif /* NVIC_STM32F446_NVIC_H_ */
