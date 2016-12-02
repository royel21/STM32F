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

#define SPI_TRANSMIT   (uint8_t)0x01
#define SPI_RECEIVE    (uint8_t)0x00
#define SPI_BRRDIV4    (uint8_t)0x01
#define SPI_BRRDIV8    (uint8_t)0x02
#define SPI_BRRDIV16   (uint8_t)0x03
#define SPI_BRRDIV32   (uint8_t)0x04
#define SPI_BRRDIV64   (uint8_t)0x05
#define SPI_BRRDIV128  (uint8_t)0x06
#define SPI_BRRDIV256  (uint8_t)0x07

class SPI
{
	private:
		SPI_TypeDef *SPIx;
		uint16_t PIN;
		GPIO_TypeDef *PORT;
	public:
		SPI(SPI_TypeDef *spi, uint16_t pins);
		void setBidiMode(uint8_t direction);
		void setCPOL(uint8_t cpol);
		void setCPHA(uint8_t cpha);
		void start(uint8_t brControl = 0);
		void softPin(GPIO_TypeDef *port, uint16_t pin);
		void chipSelect(uint8_t ss);
		uint8_t send8Byte(uint8_t);
		uint16_t send16Byte(uint16_t);
		uint8_t receive8Byte();
		uint16_t receive16Byte();
};

#endif /* SPI_H_ */
