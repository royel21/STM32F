/*
 * MAX7219.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: RoyerAriel
 */

#include "MAX7219.h"

MAX7219::MAX7219(SPI_TypeDef *spi, uint16_t pins)
{
	this->SPIx = spi;

}
