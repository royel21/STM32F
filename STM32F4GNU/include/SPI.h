/*
 * SPI.h
 *
 *  Created on: Sep 21, 2016
 *      Author: RoyerAriel
 */

#ifndef SPI_H_
#define SPI_H_
#include "cmsis_device.h"
#include "define.h"
#include "util.h"

class SPI {
	private:
		SPI_TypeDef *SPIx;
	public:
		SPI();
    void init(GPIO_TypeDef *port, SPI_TypeDef *spi, uint16_t pins, uint8_t af);
		uint8_t send8Byte(uint8_t);
		uint16_t send16Byte(uint16_t);
		uint8_t receive8Byte();
		uint16_t receive16Byte();
};

#endif /* SPI_H_ */
