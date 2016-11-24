/*
 * TIM_PWM.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: RoyerAriel
 */
#include "TIM_PWM.h"
#include "Util.h"

void TIM_PWM_Init(uint8_t frecuency)
{
	//GPIO Configuration
  GPIO_Config(GPIOA, P08 | P09, MODE_AF, PULL_UP, OTYPER_PP, SPEED_100MHz, AF_TIM1);

  uint32_t frc = (((float) 1000 / frecuency) * 1000);
	/***********************************************/
	//TIM1 peripheral Clock Bit0:1
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	//TIM1 Pre-Scale register
	TIM1->PSC = 99;
	//TIM1 auto-reload register
  TIM1->ARR = frc;
	//TIM1 capture/compare register 1
  TIM1->CCR1 = TIM1->ARR / 2;
	//TIM1 capture/compare register 2
  TIM1->CCR2 = TIM1->ARR / 2;
	//TIM1 capture/compare mode register 1
	TIM1->BDTR |= TIM_BDTR_MOE;

	/*TIM1 capture/compare mode register 1
	 * Output compare 1 preload enable      Bit3:1
	 * OC1Mode PWM                          Bit4:0
	 * OC1Mode PWM                          Bit5:1
	 * OC1Mode PWM                          Bit6:1
	 *
	 * Output compare 2 preload enable      Bit11:1
	 * OC2Mode PWM                          Bit12:0
	 * OC2Mode PWM                          Bit13:1
	 * OC2Mode PWM                          Bit14:1
	 */
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE | TIM_CCMR1_OC1PWM1 | TIM_CCMR1_OC2PE
			| TIM_CCMR1_OC2PWM1;

	/*TIM1 capture/compare enable register
	 * Channel 1                            Bit0:1
	 * channel 2                            Bit4:1
	 * channel 2 polarity active low        Bit5:1
	 */
	TIM1->CCER |= 0x31;	// and  enable

	/*TIM1 Control register 1
	 * Counter enable                       Bit0:1
	 * AutoReload pre-load                  Bit7:1
	 */
	TIM1->CR1 |= TIM_CR1_CEN | TIM_CR1_ARPE;
}

