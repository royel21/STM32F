/*
 * MAX7219.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: RoyerAriel
 */

#include "MAX7219.h"

#define NO_OP         (uint8_t)0x00
#define DECODEM       (uint8_t)0x90
#define INTENSITY     (uint8_t)0xA0
#define SCANLIMIT     (uint8_t)0xB0
#define SHUTDOWN      (uint8_t)0xC0
#define DISPLAYTEST   (uint8_t)0xF0

MAX7219::MAX7219(SPI *spi)
{
	this->SPIx = spi;
}

void MAX7219::write(uint8_t addr, uint8_t data)
{
	SPIx->chipSelect(LOW);
	SPIx->send16Byte(addr | data);
	SPIx->chipSelect(HIGH);
}

void MAX7219::setBrightness(uint8_t b)
{
	write(INTENSITY, b);
}

void MAX7219::setScanDigit(uint8_t d)
{
	write(0x0B, d);
}
void MAX7219::setDisplayON(uint8_t state)
{
	write(0x0C, state);
}

void MAX7219::setSelfTest(uint8_t state)
{
	write(0x0C, state);
}

void MAX7219::writeData(uint8_t *data)
{
	for (uint8_t i = 0; i < 8; i++)
	{
		MAX7219::write(i + 1, data[i]);
	}
}
