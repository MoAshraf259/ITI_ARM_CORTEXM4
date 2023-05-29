/*
 * led_matrix.h
 *
 *  Created on: May 28, 2023
 *      Author: moham
 */

#ifndef LED_MATRIX_LED_MATRIX_H_
#define LED_MATRIX_LED_MATRIX_H_

#include "stm32f446.h"


#define COL_PORT	GPIOA
#define ROW_PORT	GPIOE



void LED_Matrix_Init(void);
void set_row(uint8_t row, uint8_t state);
void set_col(uint8_t col, uint8_t state);
void set_pixel(uint8_t x, uint8_t y, uint8_t state);
void display_pattern(uint8_t* pattern);


#endif /* LED_MATRIX_LED_MATRIX_H_ */
