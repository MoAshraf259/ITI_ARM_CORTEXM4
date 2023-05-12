/*
 * stm32f446_gpio.h
 *
 *  Created on: May 6, 2023
 *      Author: Noursine Hafez
 */

#ifndef GPIO_STM32F446_GPIO_H_
#define GPIO_STM32F446_GPIO_H_

#include "stm32f446.h"

#define GPIO_MODE_INPUT			0
#define GPIO_MODE_OUTPUT		1
#define GPIO_MODE_ALF			2
#define GPIO_MODE_Analog		3

#define GPIO_OTYPE_PUSHPULL		0
#define GPIO_OTYPE_OPENDRAIN	1

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

#define GPIO_NOPUPD				0
#define GPIO_PU					1
#define GPIO_PD					2





typedef struct
{
	uint8_t Mode;
	uint8_t OT_Type;
	uint8_t SPEED;
	uint8_t PUPD;
	uint8_t PinNumber;
	uint8_t ALF;
}GPIO_Config_t;

typedef struct
{
	GPIO_RegDef_t *pGPIOx;
	GPIO_Config_t GPIO_Config;
}GPIO_Handle_t;


void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);

void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
uint8_t GPIO_ReadFromPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToPort(GPIO_RegDef_t *pGPIOx,uint16_t value);
#endif /* GPIO_STM32F446_GPIO_H_ */
