/*
 * leds.h
 *
 *  Created on: May 13, 2023
 *      Author: moham
 */

#ifndef LEDS_LEDS_H_
#define LEDS_LEDS_H_

#include "stm32f446.h"

void LED_ON(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
void LED_OFF(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
#endif /* LEDS_LEDS_H_ */
