/*
 * led_matrix.c
 *
 *  Created on: May 28, 2023
 *      Author: moham
 */

#include "led_matrix.h"

uint16_t Matrix_RPIN[8] = {0, 1, 2, 3, 4,5, 6, 7};
uint16_t Matrix_CPIN[8] = {0, 1, 2, 3, 4, 5, 6, 7};

void LED_Matrix_Init(void)
{
	GPIO_Handle_t LED_MatrixGPIO;
	LED_MatrixGPIO.pGPIOx=COL_PORT;
	LED_MatrixGPIO.GPIO_Config.Mode=GPIO_MODE_OUTPUT;
	LED_MatrixGPIO.GPIO_Config.OT_Type=GPIO_OTYPE_PUSHPULL;
	LED_MatrixGPIO.GPIO_Config.SPEED=GPIO_SPEED_LOW;

	for(uint8_t i=0;i<8;i++){
		LED_MatrixGPIO.GPIO_Config.PinNumber=i;
		GPIO_Init(&LED_MatrixGPIO);
	}

	LED_MatrixGPIO.pGPIOx=ROW_PORT;

	for(uint8_t i=0;i<8;i++){
			LED_MatrixGPIO.GPIO_Config.PinNumber=i;
			GPIO_Init(&LED_MatrixGPIO);
		}

	for(uint8_t i=0;i<8;i++){
		GPIO_WriteToPin(COL_PORT, i, HIGH);
	}

	for(uint8_t i=0;i<8;i++){
		GPIO_WriteToPin(ROW_PORT, i, LOW);
	}
}


void set_row(uint8_t row, uint8_t state)
{
	GPIO_WriteToPin(ROW_PORT, Matrix_RPIN[row], state ? SET : RESET);
}

void set_col(uint8_t col, uint8_t state)
{
	GPIO_WriteToPin(COL_PORT, Matrix_CPIN[col], state ? SET : RESET);
}

void set_pixel(uint8_t x, uint8_t y, uint8_t state)
{
	set_row(y,state);
	set_col(x,!state);
}

void display_pattern(uint8_t* pattern)
{
	 for (uint8_t x = 0; x < 8; x++) {
	    for (uint8_t y = 0; y < 8; y++) {
	      set_pixel(x, y, pattern[y] & (1 << x));
	    }
	 }
}
