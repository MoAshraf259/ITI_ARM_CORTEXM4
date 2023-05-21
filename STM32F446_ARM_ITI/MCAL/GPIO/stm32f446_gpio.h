/*
 * stm32f446_gpio.h
 *
 *  Created on: May 6, 2023
 *      Author: Noursine Hafez
 */

#ifndef GPIO_STM32F446_GPIO_H_
#define GPIO_STM32F446_GPIO_H_

#include "stm32f446.h"

/*GPIO Availabe modes to use by user*/
#define GPIO_MODE_INPUT			0
#define GPIO_MODE_OUTPUT		1
#define GPIO_MODE_ALF			2
#define GPIO_MODE_Analog		3

/*GPIO Output pin modes*/
#define GPIO_OTYPE_PUSHPULL		0
#define GPIO_OTYPE_OPENDRAIN	1

/*GPIO Pin speed */
#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

/*GPIO Pull UP Pull Down modes for input pins*/
#define GPIO_NOPUPD				0
#define GPIO_PU					1
#define GPIO_PD					2

/*Alternate function modes*/
#define GPIO_AF0				0
#define GPIO_AF1				1
#define GPIO_AF2				2
#define GPIO_AF3				3
#define GPIO_AF4				4
#define GPIO_AF5				5
#define GPIO_AF6				6
#define GPIO_AF7				7
#define GPIO_AF8				8
#define GPIO_AF9				9
#define GPIO_AF10				10
#define GPIO_AF11				11
#define GPIO_AF12				12
#define GPIO_AF13				13
#define GPIO_AF14				14
#define GPIO_AF15				15

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


/*All used functions for GPIO */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);

void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
uint8_t GPIO_ReadFromPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToPort(GPIO_RegDef_t *pGPIOx,uint16_t value);

void GPIO_WriteToPinFAST(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
#endif /* GPIO_STM32F446_GPIO_H_ */
