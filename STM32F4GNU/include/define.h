/*
 * MAcrosPIN.h
 *
 *  Created on: Jun 4, 2016
 *      Author: RoyerAriel
 */

#ifndef MACROSPIN_HPP_
#define MACROSPIN_HPP_
#include "cmsis_device.h"
#define USE_USART2
#define NOP						   asm("nop")

#define BIN						   ((uint8_t)0x02)
#define DEC						   ((uint8_t)0x0A)
#define HEX						   ((uint8_t)0x10)

#define TIM_CCMR1_OC1PWM1		((uint16_t)0x00000060)
#define TIM_CCMR1_OC1PWM2		((uint16_t)0x00000070)
#define TIM_CCMR1_OC2PWM1		((uint16_t)0x00006000)
#define TIM_CCMR1_OC2PWM2		((uint16_t)0x00007000)
#define TIM_CCMR2_OC3PWM1		TIM_CCMR1_OC1PWM1
#define TIM_CCMR2_OC3PWM2		TIM_CCMR1_OC1PWM2
#define TIM_CCMR2_OC4PWM1		TIM_CCMR1_OC2PWM1
#define TIM_CCMR2_OC4PWM2		TIM_CCMR1_OC2PWM2



#define MODE_IN				    ((uint8_t)0x00)
#define MODE_OUT			    ((uint8_t)0x01)
#define MODE_AF                 ((uint8_t)0x02)
#define MODE_ANG                ((uint8_t)0x03)



/******************  Bits definition for OTYPER register  ****************/
#define OTYPER_PP               ((uint8_t)0x00)
#define OTYPER_OD               ((uint8_t)0x01)

/******************  Bits definition((uint8_t)0x03)register  ***************/
#define SPEED_2MHz			    ((uint8_t)0x00)
#define SPEED_25MHz             ((uint8_t)0x01)
#define SPEED_50MHz             ((uint8_t)0x02)
#define SPEED_100MHz            ((uint8_t)0x03)


/******************  Bits definition for PUPDR register  *****************/
#define PULL_NO                 ((uint8_t)0x00)
#define PULL_UP                 ((uint8_t)0x01)
#define PULL_DOWN				((uint8_t)0x02)

/******************  Bits definition for BSRR register  ******************/
#define P00                     ((uint16_t)0x0001)
#define P01                     ((uint16_t)0x0002)
#define P02                     ((uint16_t)0x0004)
#define P03                     ((uint16_t)0x0008)
#define P04                     ((uint16_t)0x0010)
#define P05                     ((uint16_t)0x0020)
#define P06                     ((uint16_t)0x0040)
#define P07                     ((uint16_t)0x0080)
#define P08                     ((uint16_t)0x0100)
#define P09                     ((uint16_t)0x0200)
#define P10                     ((uint16_t)0x0400)
#define P11                     ((uint16_t)0x0800)
#define P12                     ((uint16_t)0x1000)
#define P13                     ((uint16_t)0x2000)
#define P14                     ((uint16_t)0x4000)
#define P15                     ((uint16_t)0x8000)

#define  ADC_CR1_12Bits			((uint32_t)0x00000000)
#define  ADC_CR1_10Bits         ((uint32_t)0x01000000)
#define  ADC_CR1_8Bits          ((uint32_t)0x02000000)
#define  ADC_CR1_6Bits          ((uint32_t)0x03000000)

#endif /* MACROSPIN_HPP_ */
