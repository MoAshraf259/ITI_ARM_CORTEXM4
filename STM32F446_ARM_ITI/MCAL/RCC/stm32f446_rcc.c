/*
 * stm32f446_rcc.c
 *
 *  Created on: May 4, 2023
 *      Author: moham
 */

#include "stm32f446_rcc.h"

void SetClockSystem(void)
{
#if	SYSTEM_CLK_SRC	== HSI
	RCC->CR |= (1<<0); //Right 1 to the HSI ON Bit to enable the HSI Clock
	RCC->CFGR &=~(3<<0); //right to SW Bits to choose the HSI As the source clock
	RCC->CFGR |= (AHB_PRESCALER<<4);//Set the AHB PRESCLAER as predefined value
	RCC->CFGR |= (APB1_PRESCLAER<<10);//Set the APB1 PRESCLAER as predefined value
	RCC->CFGR |= (APB2_PRESCLAER<<13);//Set the APB2 PRESCLAER as predefined value

#elif	SYSTEM_CLK_SRC	== HSE
	RCC->CR |= (1<<16);//ENABLE HSE CLOCK
	RCC->CR |= (1<<18);//Choose RC External "HSE"
	RCC->CFGR |= (1<<0);
	RCC->CFGR &=~ (1<<1);
	RCC->CFGR |= (AHB_PRESCALER<<4);
	RCC->CFGR |= (APB1_PRESCLAER<<10);
	RCC->CFGR |= (APB2_PRESCLAER<<13);

#elif	SYSTEM_CLK_SRC	== HSE_CRYS
	RCC->CR   |= 	(1<<16);//ENABLE HSE CLOCK
	RCC->CR   &= ~	(1<<18);//Choose RC External
	RCC->CFGR |= 	(1<<0);
	RCC->CFGR &= ~ 	(1<<1);
	RCC->CFGR |= (AHB_PRESCALER<<4);
	RCC->CFGR |= (APB1_PRESCLAER<<10);
	RCC->CFGR |= (APB2_PRESCLAER<<13);

#elif SYSTEM_CLK_SRC	== PLL
#else
#error("Wrong system clock")

#endif
}

void RCC_EnablePeripheral(uint8_t BUS_ID,uint8_t PeripheralID)
{
	switch (BUS_ID){
		case AHB1:
			RCC->AHB1ENR |=(1<<PeripheralID);
			break;

		case AHB2:
			RCC->AHB2ENR |=(1<<PeripheralID);
			break;

		case APB1:
			RCC->APB1ENR |=(1<<PeripheralID);
			break;

		case APB2:
			RCC->APB2ENR |=(1<<PeripheralID);
				break;

		default :
			break;
	}



}

void RCC_DisablePeripheral(uint8_t BUS_ID,uint8_t PeripheralID)
{
	switch (BUS_ID){
		case AHB1:
			RCC->AHB1ENR &= ~(1<<PeripheralID);
			break;

		case AHB2:
			RCC->AHB2ENR &= ~(1<<PeripheralID);
			break;

		case APB1:
			RCC->APB1ENR &= ~(1<<PeripheralID);
			break;

		case APB2:
			RCC->APB2ENR &= ~(1<<PeripheralID);
				break;

		default :
			break;
	}
}

uint16_t AHB_PreScaler[8] = {2,4,8,16,64,128,256,512};
uint8_t APB1_PreScaler[4] = { 2, 4 , 8, 16};



uint32_t RCC_GetPCLK1Value(void)
{
	uint32_t pclk1,SystemClk;

	uint8_t clksrc,temp,ahbp/*AHB PRESCALER*/,apb1p/*APB1 PRESCALER*/;

	clksrc = ((RCC->CFGR >> 2) & 0x3);//Checking the configured clock source

	if(clksrc == 0 )//if it`s equal to 0 then the used clock is HSI
	{
		SystemClk = 16000000; //Our HSI Clock is 16MHz
	}

	else if(clksrc == 1)//This case it`s the HSE used as the clock source
	{
		SystemClk = 8000000;//STM32F446RE External clock is 8Mhz
							//"It may vary from another boards"
	}

	else if (clksrc == 2)//Not Covered PLL
	{
		SystemClk = RCC_GetPLLOutputClock();
	}

	//for ahb
	temp = ((RCC->CFGR >> 4 ) & 0xF);//Getting the PRESCALER of the AHB Bus

	if(temp < 8)//If less than 8 then there is not PRESCALER
	{
		ahbp = 1;//PRESCALER Value is 1
	}else
	{
		ahbp = AHB_PreScaler[temp-8];//If it`s more than one then it will increase
									 //step by step as the array is defining
	}



	//apb1
	temp = ((RCC->CFGR >> 10 ) & 0x7);//Checking the PRESCALER value of the APB1 Bus

	if(temp < 4)//Starting here from 4 if it`s less than 4 there is not PRESCALER
	{
		apb1p = 1;
	}else
	{
		apb1p = APB1_PreScaler[temp-4];//If it`s more than one then it will increase
		 	 	 	 	 	 	 	 	 //step by step as the array is defining
	}

	pclk1 =  (SystemClk / ahbp) /apb1p;	//The result clock is calculated here !

	return pclk1;
}


uint32_t RCC_GetPCLK2Value(void)
{
	uint32_t SystemClock=0,tmp,pclk2;

	uint8_t clk_src = ( RCC->CFGR >> 2) & 0X3;//Checking the configured clock source

	uint8_t ahbp,apb2p;

	if(clk_src == 0) //if it`s equal to 0 then the used clock is HSI
	{
		SystemClock = 16000000; //Which is in our case is 16MHz
	}else
	{
		SystemClock = 8000000;/*if not equal to zero we must configure it
							  /in STM32F446RE the HSE is 8MHz*/
	}
	tmp = (RCC->CFGR >> 4 ) & 0xF; //We get the PRESCALER of the AHB Bus (1,2)

	if(tmp < 0x08)
	{
		ahbp = 1; /*As the reset value for the PRESCALER starts from 0b0000
				   and the next value is 0b1000 = 8 == PRESCALER /2
				  if it`s less than 8 then there is not PRESCALER*/
	}else
	{
       ahbp = AHB_PreScaler[tmp-8];
       /*Starting from 8 the AHB PRESCALER starts increasing step by step according to the
        * array defined here */

	}

	//for the APB2
	tmp = (RCC->CFGR >> 13 ) & 0x7;//Checking the PRESCALER value of the APB2 Bus
	if(tmp < 0x04)
	{
		apb2p = 1;
	}else
	{
		apb2p = APB1_PreScaler[tmp-4];//If it`s more than one then it will increase
										//step by step as the array is defining
	}

	pclk2 = (SystemClock / ahbp )/ apb2p;//The result clock is calculated here !

	return pclk2;
}

uint32_t  RCC_GetPLLOutputClock(void)
{
	//Not covered
	return 0;
}
