/*
 * keypad.c
 *
 *  Created on: May 15, 2023
 *      Author: moham
 */

#include "keypad.h"


void Keypad_Init(void){
	GPIO_Handle_t Keypad_Handle;

		Keypad_Handle.pGPIOx=KEYPAD_PORT;
		Keypad_Handle.GPIO_Config.Mode=GPIO_MODE_OUTPUT;
		Keypad_Handle.GPIO_Config.OT_Type=GPIO_OTYPE_PUSHPULL;
		Keypad_Handle.GPIO_Config.SPEED=GPIO_SPEED_FAST;
		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_R0;

		GPIO_Init(&Keypad_Handle);

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_R1;
		GPIO_Init(&Keypad_Handle);

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_R2;
		GPIO_Init(&Keypad_Handle);

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_R3;
		GPIO_Init(&Keypad_Handle);

		/*/////////////////////////////////////////////*/
		/*This part for configuring the rows as inputs*/
		/*/////////////////////////////////////////////*/
		Keypad_Handle.GPIO_Config.PinNumber=GPIO_MODE_INPUT;
		Keypad_Handle.GPIO_Config.PUPD=GPIO_PU;

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_C0;
		GPIO_Init(&Keypad_Handle);

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_C1;
		GPIO_Init(&Keypad_Handle);

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_C2;
		GPIO_Init(&Keypad_Handle);

		Keypad_Handle.GPIO_Config.PinNumber=KEYPAD_C3;
		GPIO_Init(&Keypad_Handle);

}

uint8_t Keypad_GetPressed(void){
	//WE will be checking on the Columns
	uint8_t Pressed_Key=0;
	uint8_t temp_val;

	uint8_t KEYPAD_ARR[4][4]=KPD_VALUES;

	uint8_t KEYPAD_ROW[4]={KEYPAD_R0,KEYPAD_R1,KEYPAD_R2,KEYPAD_R3};
	uint8_t KEYPAD_COL[4]={KEYPAD_C0,KEYPAD_C1,KEYPAD_C2,KEYPAD_C3};

	for(uint8_t row=0;row<4;row++)
	{
		GPIO_WriteToPin(KEYPAD_PORT, KEYPAD_ROW[row], LOW);

		for(uint8_t col=0;col<4;col++)
		{
			temp_val=GPIO_ReadFromPin(KEYPAD_PORT, KEYPAD_COL[col]);

			if(temp_val==LOW){
			Pressed_Key=KEYPAD_ARR[row][col];
			}
		}
		GPIO_WriteToPin(KEYPAD_PORT, KEYPAD_ROW[row], HIGH);
	}

	return Pressed_Key;
}
