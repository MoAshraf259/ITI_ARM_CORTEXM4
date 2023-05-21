/*
 * ssd.c
 *
 *  Created on: May 13, 2023
 *      Author: moham
 */


#include "ssd.h"

GPIO_Handle_t SSD_PinHandle;
void SSD_Init(void)
{
	SSD_PinHandle.pGPIOx=SSD_Port;
	SSD_PinHandle.GPIO_Config.Mode=GPIO_MODE_OUTPUT;
	SSD_PinHandle.GPIO_Config.OT_Type=GPIO_OTYPE_PUSHPULL;
	SSD_PinHandle.GPIO_Config.SPEED=GPIO_SPEED_FAST;

	SSD_PinHandle.GPIO_Config.PinNumber=0;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=1;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=2;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=3;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=4;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=5;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=6;
	GPIO_Init(&SSD_PinHandle);

	SSD_PinHandle.GPIO_Config.PinNumber=7;
	GPIO_Init(&SSD_PinHandle);

}

void SSDDispNum(GPIO_RegDef_t *pDIO,uint8_t value)
{
#if SSDType==CA
	{
		switch(value)
		{
		case 0:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ZERO;
			break;

		case 1:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ONE;
			break;

		case 2:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= TWO;
			break;

		case 3:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= THREE;
			break;

		case 4:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= FOUR;
			break;

		case 5:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= FIVE;
			break;

		case 6:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= SIX;
			break;

		case 7:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= SEVEN;
			break;

		case 8:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= EIGHT;
			break;

		case 9:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= NINE;
			break;
		}
	}

#elif SSDType==CC
	{
		switch(value)
		{
		case 0:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~ZERO;
			break;

		case 1:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~ONE;
			break;

		case 2:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |=  ~TWO;
			break;

		case 3:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~THREE;
			break;

		case 4:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~FOUR;
			break;

		case 5:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~FIVE;
			break;

		case 6:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~SIX;
			break;

		case 7:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~SEVEN;
			break;

		case 8:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~EIGHT;
			break;

		case 9:
			SSD_Port->ODR &= ~(0x00FF);
			SSD_Port->ODR |= ~NINE;
			break;
		}
	}
#endif
}
