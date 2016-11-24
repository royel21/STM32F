/*
 * SPI.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: RoyerAriel
 */

#include "SPI.h"

SPI::SPI()
{
	SPIx = 0;
}

void SPI::init(SPI_TypeDef *spi, uint16_t pins, uint8_t brControl)
{
	this->SPIx = spi;
  if (spi == SPI1)
  {
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
  } else if (spi == SPI2)
  {
    RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
  }
  GPIO_Config(GPIOB, pins, MODE_AF, PULL_NO, OTYPER_PP, SPEED_100MHz, AF_SPI1);

//	SPI_InitTypeDef SPI_InitSt;
//	SPI_InitSt.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
//	SPI_InitSt.SPI_Mode = SPI_Mode_Master;
//	SPI_InitSt.SPI_DataSize = SPI_DataSize_8b;
//	SPI_InitSt.SPI_CPOL = SPI_CPOL_High;
//	SPI_InitSt.SPI_CPHA = SPI_CPHA_1Edge;
//	SPI_InitSt.SPI_NSS = SPI_NSS_Soft;
//	SPI_InitSt.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
//	SPI_InitSt.SPI_FirstBit = SPI_FirstBit_MSB;
//	SPI_InitSt.SPI_CRCPolynomial = 7;
//

//	SPI_Init(SPIx, &SPI_InitSt);
  SPIx->CR1 |= SPI_CR1_CPOL | SPI_CR1_MSTR | (brControl << 3);
  SPIx->CR1 |= SPI_CR1_SPE;


}

uint8_t SPI::send8Byte(uint8_t Byte)
{
  while ((SPIx->SR & SPI_SR_TXE) == RESET)
    ;
	SPIx->DR=Byte;
	//while((SPIx->SR&SPI_I2S_FLAG_RXNE)==RESET);
	return SPIx->DR & 0xFF;
}
