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
#define USE_USART6
#define NOP						   asm("nop")

#define BIN						   ((uint8_t)0x02)
#define DEC						   ((uint8_t)0x0A)
#define HEX						   ((uint8_t)0x10)
#define LOW						   ((uint8_t)0x00)
#define HIGH					   ((uint8_t)0x01)
#define ON							  ((uint8_t)0x00)
#define OFF							  ((uint8_t)0x01)

#ifdef STM32F1
#define MODE_IN                (uint8_t)0x00
#define MODE_OUT_2MHZ          (uint8_t)0x02
#define MODE_OUT_10MHZ         (uint8_t)0x01
#define MODE_OUT_50MHZ         (uint8_t)0x03

#define CNF_IN_ANG             (uint8_t)0x00
#define CNF_IN_FLOAT           (uint8_t)0x40
#define CNF_IN_PULL            (uint8_t)0x80

#define CNF_OUT_PP             (uint8_t)0x00
#define CNF_OUT_OD             (uint8_t)0x40
#define CNF_OUT_AFPP           (uint8_t)0x80
#define CNF_OUT_AFDD           (uint8_t)0xC0
#endif
#ifdef STM32F4
#define TIM_CCMR1_OC1PWM1		((uint16_t)0x00000060)
#define TIM_CCMR1_OC1PWM2		((uint16_t)0x00000070)
#define TIM_CCMR1_OC2PWM1		((uint16_t)0x00006000)
#define TIM_CCMR1_OC2PWM2		((uint16_t)0x00007000)
#define TIM_CCMR2_OC3PWM1		TIM_CCMR1_OC1PWM1
#define TIM_CCMR2_OC3PWM2		TIM_CCMR1_OC1PWM2
#define TIM_CCMR2_OC4PWM1		TIM_CCMR1_OC2PWM1
#define TIM_CCMR2_OC4PWM2		TIM_CCMR1_OC2PWM2

#define MODE_IN				          ((uint8_t)0x00)
#define MODE_OUT			          ((uint8_t)0x01)
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

#define  ADC_CR1_12Bits			    ((uint32_t)0x00000000)
#define  ADC_CR1_10Bits         ((uint32_t)0x01000000)
#define  ADC_CR1_8Bits          ((uint32_t)0x02000000)
#define  ADC_CR1_6Bits          ((uint32_t)0x03000000)

#define  USART_CR1_W9bits       ((uint16_t)0x1000)            /*!<Word length*/

#define  USART_CR2_STOP_0_5     ((uint16_t)0x1000)            /*!<Bit 0 */
#define  USART_CR2_STOP_1_0     ((uint16_t)0x0000)            /*!<Bit 1 */
#define  USART_CR2_STOP_2_0     ((uint16_t)0x2000)            /*!<Bit 1 */

#define AF_RTC_50Hz      ((uint8_t)0x00)  /* RTC_50Hz Alternate Function mapping */
#define AF_MCO           ((uint8_t)0x00)  /* MCO (MCO1 and MCO2) Alternate Function mapping */
#define AF_TAMPER        ((uint8_t)0x00)  /* TAMPER (TAMPER_1 and TAMPER_2) Alternate Function mapping */
#define AF_SWJ           ((uint8_t)0x00)  /* SWJ (SWD and JTAG) Alternate Function mapping */
#define AF_TRACE         ((uint8_t)0x00)  /* TRACE Alternate Function mapping */

#define AF_TIM1          ((uint8_t)0x01)  /* TIM1 Alternate Function mapping */
#define AF_TIM2          ((uint8_t)0x01)  /* TIM2 Alternate Function mapping */

/**
 * @brief   AF 2 selection
 */
#define AF_TIM3          ((uint8_t)0x02)  /* TIM3 Alternate Function mapping */
#define AF_TIM4          ((uint8_t)0x02)  /* TIM4 Alternate Function mapping */
#define AF_TIM5          ((uint8_t)0x02)  /* TIM5 Alternate Function mapping */

/**
 * @brief   AF 3 selection
 */
#define AF_TIM8          ((uint8_t)0x03)  /* TIM8 Alternate Function mapping */
#define AF_TIM9          ((uint8_t)0x03)  /* TIM9 Alternate Function mapping */
#define AF_TIM10         ((uint8_t)0x03)  /* TIM10 Alternate Function mapping */
#define AF_TIM11         ((uint8_t)0x03)  /* TIM11 Alternate Function mapping */

#define AF_USART1         ((uint8_t)0x07)  /* USART1 Alternate Function mapping  */
#define AF_USART2         ((uint8_t)0x07)  /* USART2 Alternate Function mapping  */
#define AF_USART3         ((uint8_t)0x07)  /* USART3 Alternate Function mapping  */

#define AF_UART4         ((uint8_t)0x08)  /* UART4 Alternate Function mapping  */
#define AF_UART5         ((uint8_t)0x08)  /* UART5 Alternate Function mapping  */
#define AF_USART6        ((uint8_t)0x08)  /* USART6 Alternate Function mapping */
#define AF_UART7         ((uint8_t)0x08)  /* UART7 Alternate Function mapping  */
#define AF_UART8         ((uint8_t)0x08)  /* UART8 Alternate Function mapping  */

#define AF_I2C           ((uint8_t)0x04)  /* I2C1 Alternate Function mapping */
#define AF_SPI           ((uint8_t)0x05)  /* SPI1/I2S1 Alternate Function mapping */

#define AF7_SPI3          ((uint8_t)0x07)  /* SPI3/I2S3ext Alternate Function mapping */
#define AF_SPI3          ((uint8_t)0x06)  /* SPI3/I2S3 Alternate Function mapping */
#define AF6_SPI1         ((uint8_t)0x06)  /* SPI1 Alternate Function mapping (Only for STM32F410xx Devices) */
#define AF6_SPI2         ((uint8_t)0x06)  /* SPI2 Alternate Function mapping (Only for STM32F410xx/STM32F411xE Devices) */
#define AF6_SPI4         ((uint8_t)0x06)  /* SPI4 Alternate Function mapping (Only for STM32F411xE Devices) */
#define AF6_SPI5         ((uint8_t)0x06)  /* SPI5 Alternate Function mapping (Only for STM32F410xx/STM32F411xE Devices) */
#define AF_SAI1          ((uint8_t)0x06)  /* SAI1 Alternate Function mapping      */
#define AF_I2S2ext       ((uint8_t)0x06)  /* I2S2ext_SD Alternate Function mapping (only for STM32F412xG Devices) */

#define AF_SDIO          ((uint8_t)0xC)
#define AF_OTG_HS_FS     ((uint8_t)0xC)
#define AF_EVENTOUT      ((uint8_t)0x0F)
#define AF_OTG_FS        ((uint8_t)0xA)  /* OTG_FS Alternate Function mapping */
#define AF_OTG_HS        ((uint8_t)0xA)  /* OTG_HS Alternate Function mapping */

#define AF_CAN1          ((uint8_t)0x09)  /* CAN1 Alternate Function mapping  */
#define AF_CAN2          ((uint8_t)0x09)  /* CAN2 Alternate Function mapping  */
#define AF_TIM12         ((uint8_t)0x09)  /* TIM12 Alternate Function mapping */
#define AF_TIM13         ((uint8_t)0x09)  /* TIM13 Alternate Function mapping */
#define AF_TIM14         ((uint8_t)0x09)  /* TIM14 Alternate Function mapping */
#define AF9_I2C2         ((uint8_t)0x09)  /* I2C2 Alternate Function mapping (Only for STM32F401xx/STM32F410xx/STM32F411xE/STM32F412xG Devices) */
#define AF9_I2C3         ((uint8_t)0x09)  /* I2C3 Alternate Function mapping (Only for STM32F401xx/STM32F411xE/STM32F412xG Devices) */
#endif

#endif /* MACROSPIN_HPP_ */
