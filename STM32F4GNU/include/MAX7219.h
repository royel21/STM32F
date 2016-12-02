/*
 * MAX7219.h
 *
 *  Created on: Nov 30, 2016
 *      Author: RoyerAriel
 */

#ifndef MAX7219_H_
#define MAX7219_H_

#include "cmsis_device.h"
#include "define.h"
#include "util.h"

#include "SPI.h"
#include "define.h"

class MAX7219
{
	public:
		MAX7219(SPI *spi);
		void write(uint8_t addr, uint8_t data);
		void setBrightness(uint8_t b);
		void setScanDigit(uint8_t d);
		void setDisplayON(uint8_t state);
		void setSelfTest(uint8_t state);
		void writeData(uint8_t *word);
	private:
		SPI *SPIx;
};

#endif /* MAX7219_H_ */
