/*
 * stm32f446_gpio.c
 *
 *  Created on: May 6, 2023
 *      Author: Mohamed Ashraf
 */

#include "stm32f446_gpio.h"
static void GPIO_EnablePeriClock(GPIO_Handle_t *pGPIO_Handle);

static void GPIO_EnablePeriClock(GPIO_Handle_t *pGPIO_Handle)
{
	if(pGPIO_Handle->pGPIOx==GPIOA)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOA);
	}
	else if(pGPIO_Handle->pGPIOx==GPIOB)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOB);
	}
	else if(pGPIO_Handle->pGPIOx==GPIOC)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOC);
	}
	else if(pGPIO_Handle->pGPIOx==GPIOD)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOD);
	}
	else if(pGPIO_Handle->pGPIOx==GPIOE)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOE);
	}
	else if(pGPIO_Handle->pGPIOx==GPIOF)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOF);
	}
	else if(pGPIO_Handle->pGPIOx==GPIOG)
	{
		RCC_EnablePeripheral(AHB1, AHB1_GPIOG);
	}

}
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle)
{
	uint32_t temp=0;

	/*Enable the RCC clock for the GPIO*/
	GPIO_EnablePeriClock(pGPIO_Handle);

	if(pGPIO_Handle->GPIO_Config.Mode <=GPIO_MODE_Analog)
	{
		/*This part is to SET the mode of the GPIO Pin*/
		temp=(pGPIO_Handle->GPIO_Config.Mode << 2*pGPIO_Handle->GPIO_Config.PinNumber);
		pGPIO_Handle->pGPIOx->MODER &= ~(3<<2*pGPIO_Handle->GPIO_Config.PinNumber);
		pGPIO_Handle->pGPIOx->MODER |=temp ;

	}
	else{
		//later
	}

	/*This part for configurting the OUTPUT pin type*/
	temp= pGPIO_Handle->GPIO_Config.OT_Type <<pGPIO_Handle->GPIO_Config.PinNumber;
	pGPIO_Handle->pGPIOx->OTYPER &= ~(1<<pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->pGPIOx->OTYPER |= temp;
	/*This part is to configure the speed of the pin*/
	temp= pGPIO_Handle->GPIO_Config.SPEED <<2*pGPIO_Handle->GPIO_Config.PinNumber;
	pGPIO_Handle->pGPIOx->OTYPER &= ~(3<<2*pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->pGPIOx->OTYPER |= temp;

	 /*This part is to Configure the pin PullUp PullDownResistor*/
	temp= pGPIO_Handle->GPIO_Config.PUPD <<pGPIO_Handle->GPIO_Config.PinNumber;
	pGPIO_Handle->pGPIOx->PUPDR &= ~(1<<pGPIO_Handle->GPIO_Config.PinNumber);
	pGPIO_Handle->pGPIOx->PUPDR |= temp;


	/*Alternate MODE later */

	/*External Interrupt Later*/
}
void GPIO_WriteToPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value)
{
	if(value==DISABLE){
	pGPIOx->ODR &=~(1<<PinNumber);
	}
	else{
		pGPIOx->ODR |=(1<<PinNumber);
	}
}

void GPIO_WriteToPort(GPIO_RegDef_t *pGPIOx,uint16_t value)
{
	pGPIOx->ODR =value;
}

uint8_t GPIO_ReadFromPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	if((pGPIOx->IDR>>PinNumber) & (0x1))
	{
		return SET;
	}
	else
	{
		return RESET;
	}

}
uint16_t GPIO_ReadFromPort(GPIO_RegDef_t *pGPIOx)
{
	uint16_t value;

	value=(uint16_t) pGPIOx->IDR;

	return value;
}

void GPIO_TogglePin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR ^=(1<<PinNumber);
}
