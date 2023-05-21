/*
 * leds.c
 *
 *  Created on: May 13, 2023
 *      Author: moham
 */

#include "leds.h"


void LED_ON(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR |=(1<<PinNumber);
}

void LED_OFF(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber)
{
	pGPIOx->ODR &= ~(1<<PinNumber);
}
