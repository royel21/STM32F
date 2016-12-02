/*
 * SPI.cpp
 *
 *  Created on: Sep 21, 2016
 *      Author: RoyerAriel
 */

#include "SPI.h"

SPI::SPI(SPI_TypeDef *spi, uint16_t pins)
{
	PORT = 0;
	PIN = 0;
	this->SPIx = spi;
	if (spi == SPI1)
	{
		RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	} else if (spi == SPI2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
	}
	GPIO_Config(GPIOA, pins, MODE_AF, PULL_DOWN, OTYPER_PP, SPEED_50MHz, AF_SPI);

}

void SPI::setBidiMode(uint8_t direction)
{
	SPIx->CR1 |= SPI_CR1_BIDIMODE | (direction << 14);
}

void SPI::setCPHA(uint8_t cpha)
{
	cpha ? SPIx->CR1 |= SPI_CR1_SPE | SPI_CR1_CPHA : SPIx->CR1 &= ~SPI_CR1_CPHA;
}

void SPI::setCPOL(uint8_t cpol)
{
	cpol ? SPIx->CR1 |= SPI_CR1_CPOL : SPIx->CR1 &= ~SPI_CR1_CPOL;
}

void SPI::softPin(GPIO_TypeDef *port, uint16_t pin)
{
	GPIO_Config(port, pin, MODE_OUT, PULL_UP);
	PORT = port;
	PIN = pin;
	port->BSRRL |= pin;
}

void SPI::chipSelect(uint8_t ss)
{
	ss ? PORT->BSRRL |= PIN : PORT->BSRRH |= PIN;
}

void SPI::start(uint8_t brr)
{
//	//SPIx->CR1 |= (br << 3) | SPI_CR1_DFF;
//	SPIx->CR1 |= (brr < 3) | SPI_CR1_SSM | SPI_CR1_SSI;
//	SPIx->CR1 |= SPI_CR1_MSTR | SPI_CR1_SPE;

	SPIx->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI | (brr << 3) | SPI_CR1_MSTR | SPI_CR1_DFF;

	SPIx->CR1 |= SPI_CR1_SPE;
}

uint8_t SPI::send8Byte(uint8_t Byte)
{
	while ((SPIx->SR & SPI_SR_TXE) == RESET)
		;
	SPIx->DR = Byte;
	while ((SPIx->SR & SPI_SR_RXNE) == RESET)
		;
	return SPIx->DR & 0xFF;
}

uint16_t SPI::send16Byte(uint16_t word)
{
	while ((SPIx->SR & SPI_SR_TXE) == RESET)
		;
	SPIx->DR = word;
	while ((SPIx->SR & SPI_SR_RXNE) == RESET)
		;
	return SPIx->DR & 0xFFFF;
}
