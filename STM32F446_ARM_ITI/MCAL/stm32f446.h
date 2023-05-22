/*
 * stm32f446.h
 *
 *  Created on: May 4, 2023
 *      Author: moham
 */

#ifndef STM32F446_H_
#define STM32F446_H_

#include <stdint.h>
#define __vo volatile

#define SET		1
#define RESET	0
#define ENABLE	SET
#define DISABLE	RESET
#define HIGH	ENABLE
#define LOW		DISABLE
/*
 * AHBx and APBx Bus Peripheral base addresses
 */

#define PERIPH_BASEADDR 						0x40000000U
#define APB1PERIPH_BASEADDR						PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR						0x40010000U
#define AHB1PERIPH_BASEADDR						0x40020000U
#define AHB2PERIPH_BASEADDR						0x50000000U


/*
 * Base addresses of peripherals which are hanging on AHB1 bus
 *   : Complete for all other peripherals
 */
#define GPIOA_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                   (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR 					 (AHB1PERIPH_BASEADDR + 0x1C00)
#define CRC_BASEADDR					 (AHB1PERIPH_BASEADDR + 0x3000)
#define RCC_BASEADDR                     (AHB1PERIPH_BASEADDR + 0x3800)


#define NVIC_BASEADDR					 (0xE000E100)
#define EXTI_BASEADDR					 (0x40013C00)

#define SYSCFG_BASEADDR					(0x40013800)

typedef struct
{
	__vo uint32_t MODER;                 /*!< GPIO port mode register,      Address offset: 0x00      */
	__vo uint32_t OTYPER;                /*!<  TYPE OF OUTPUT PINS     		Address offset: 0x04      */
	__vo uint32_t OSPEEDR;					/*	*/
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];				/*!< AFR[0] : GPIO alternate function low register, AF[1] : GPIO alternate function high register    		Address offset: 0x20-0x24 */
}GPIO_RegDef_t;

/*
 * peripheral register definition structure for RCC
 */
typedef struct
{
  __vo uint32_t CR;            /*!< ,     				Address offset: 0x00 */
  __vo uint32_t PLLCFGR;       /*!< ,     				Address offset: 0x04 */
  __vo uint32_t CFGR;          /*!< ,     				Address offset: 0x08 */
  __vo uint32_t CIR;           /*!< ,     				Address offset: 0x0C */
  __vo uint32_t AHB1RSTR;      /*!< ,     				Address offset: 0x10 */
  __vo uint32_t AHB2RSTR;      /*!< ,     				Address offset: 0x14 */
  __vo uint32_t AHB3RSTR;      /*!< ,     				Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                       */
  __vo uint32_t APB1RSTR;      /*!< ,     				Address offset: 0x20 */
  __vo uint32_t APB2RSTR;      /*!< ,     				Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                  */
  __vo uint32_t AHB1ENR;       /*!< ,     				Address offset: 0x30 */
  __vo uint32_t AHB2ENR;       /*!< ,     				Address offset: 0x34 */
  __vo uint32_t AHB3ENR;       /*!< ,     				Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                       */
  __vo uint32_t APB1ENR;       /*!< ,     				Address offset: 0x40 */
  __vo uint32_t APB2ENR;       /*!< ,     				Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                  */
  __vo uint32_t AHB1LPENR;     /*!< ,     				Address offset: 0x50 */
  __vo uint32_t AHB2LPENR;     /*!< ,     				Address offset: 0x54 */
  __vo uint32_t AHB3LPENR;     /*!< ,     				Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                       */
  __vo uint32_t APB1LPENR;     /*!< ,     				Address offset: 0x60 */
  __vo uint32_t APB2LPENR;     /*!< R ,     			Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                  */
  __vo uint32_t BDCR;          /*!< ,     				Address offset: 0x70 */
  __vo uint32_t CSR;           /*!< ,     				Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                  */
  __vo uint32_t SSCGR;         /*!< ,     				Address offset: 0x80 */
  __vo uint32_t PLLI2SCFGR;    /*!< ,     				Address offset: 0x84 */
  __vo uint32_t PLLSAICFGR;    /*!< ,     				Address offset: 0x88 */
  __vo uint32_t DCKCFGR;       /*!< ,     				Address offset: 0x8C */
  __vo uint32_t CKGATENR;      /*!< ,     				Address offset: 0x90 */
  __vo uint32_t DCKCFGR2;      /*!< ,     				Address offset: 0x94 */

} RCC_RegDef_t;

typedef struct{
	__vo uint32_t ISER[32];
	__vo uint32_t ICER[32];
	__vo uint32_t ISPR[32];
	__vo uint32_t ICPR[32];
	__vo uint32_t IABR[64];
	__vo uint32_t IPR[60];
}NVIC_RegDef_t;

typedef struct{
	__vo uint32_t IMR;
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;
}EXTI_RegDef_t;


typedef struct{
	__vo uint32_t SYSCFG;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t CMPCR;
	__vo uint32_t CFGR;
}SYSCFG_RegDef_t;

#define SYSCFG				((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
#define EXTI				((EXTI_RegDef_t*)EXTI_BASEADDR)
#define NVIC				((NVIC_RegDef_t*)NVIC_BASEADDR)


#define GPIOA  				((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB  				((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC  				((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD  				((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE  				((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF  				((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG  				((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH  				((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC 				((RCC_RegDef_t*)RCC_BASEADDR)

#define RCB_AIRCR			(*((__vo uint32_t*)0xE000ED00+0x0C))

#define GPIO_PIN_NO_0		0
#define GPIO_PIN_NO_1		1
#define GPIO_PIN_NO_2		2
#define GPIO_PIN_NO_3		3
#define GPIO_PIN_NO_4		4
#define GPIO_PIN_NO_5		5
#define GPIO_PIN_NO_6		6
#define GPIO_PIN_NO_7		7
#define GPIO_PIN_NO_8		8
#define GPIO_PIN_NO_9		9
#define GPIO_PIN_NO_10		10
#define GPIO_PIN_NO_11		11
#define GPIO_PIN_NO_12		12
#define GPIO_PIN_NO_13		13
#define GPIO_PIN_NO_14		14
#define GPIO_PIN_NO_15		15

#define GPIO_PORT_TO_NUMBER(x)		((x==GPIOA)? 0:\
									(x==GPIOB)? 1:\
									(x==GPIOC)?	2:\
									(x==GPIOD)?	3:\
									(x==GPIOE)?	4:\
									(x==GPIOF)?	5:\
									(x==GPIOG)?	6:\
									(x==GPIOH)?	7:0)

#include "stm32f446_rcc.h"
#include "stm32f446_gpio.h"
#include "stm32f446_nvic.h"
#include "stm32f446_exti.h"
#endif /* STM32F446_H_ */
