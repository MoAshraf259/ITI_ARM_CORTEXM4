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

		GPIO_EnablePeriClock(pGPIO_Handle);

		//Clear the 2 bits of the bit number mode
		pGPIO_Handle->pGPIOx->MODER &=~( 3 << 2*pGPIO_Handle->GPIO_Config.PinNumber);
		// set the value of the mode entered by user
		pGPIO_Handle->pGPIOx->MODER |= (pGPIO_Handle->GPIO_Config.Mode<<2*pGPIO_Handle->GPIO_Config.PinNumber);

		//Choose the PullUpPullDown Register
		pGPIO_Handle->pGPIOx->PUPDR |= (pGPIO_Handle->GPIO_Config.PUPD<<pGPIO_Handle->GPIO_Config.PinNumber);

		//Choose the pin type whether it`s open drain or PushPull
		pGPIO_Handle->pGPIOx->OTYPER |= (pGPIO_Handle->GPIO_Config.OT_Type<<pGPIO_Handle->GPIO_Config.PinNumber);

		//Set the speed of the pin
		pGPIO_Handle->pGPIOx->OSPEEDR &=~ (3<<2*pGPIO_Handle->GPIO_Config.PinNumber);
		pGPIO_Handle->pGPIOx->OSPEEDR |= (pGPIO_Handle->GPIO_Config.SPEED<<2*pGPIO_Handle->GPIO_Config.PinNumber);

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
