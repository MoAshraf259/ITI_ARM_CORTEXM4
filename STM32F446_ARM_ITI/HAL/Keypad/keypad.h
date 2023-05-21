/*
 * keypad.h
 *
 *  Created on: May 15, 2023
 *      Author: moham
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_

#include "stm32f446.h"

#define KPD_VALUES  {{'7', '8' , '9' , '/'}\
					,{'4', '5' , '6' , '*'}\
					,{'1', '2' , '3' , '-'}\
					,{'k', '0' , '=' , '+'}}


#define KEYPAD_PORT		GPIOB

#define KEYPAD_R0		GPIO_PIN_NO_0
#define KEYPAD_R1		GPIO_PIN_NO_1
#define KEYPAD_R2		GPIO_PIN_NO_2
#define KEYPAD_R3		GPIO_PIN_NO_3

#define KEYPAD_C0		GPIO_PIN_NO_4
#define KEYPAD_C1		GPIO_PIN_NO_5
#define KEYPAD_C2		GPIO_PIN_NO_6
#define KEYPAD_C3		GPIO_PIN_NO_7

void Keypad_Init(void);

uint8_t Keypad_GetPressed(void);

#endif /* KEYPAD_KEYPAD_H_ */
