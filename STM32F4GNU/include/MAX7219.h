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

#define DG0 0x01
#define DG1 0x02
#define DG2 0x03
#define DG3 0x04
#define DG4 0x05
#define DG5 0x06
#define DG6 0x07
#define DG7 0x08

#define NODECMODE    0x0900 //
#define LIGHTINT     0x0A //

#define SCANLMTDIG0      0x0B00 //Scan Limit
#define SCANLMTDIG1      0x0B01 //Scan Limit
#define SCANLMTDIG2      0x0B02 //Scan Limit
#define SCANLMTDIG3      0x0B03 //Scan Limit
#define SCANLMTDIG4      0x0B04 //Scan Limit
#define SCANLMTDIG5      0x0B05 //Scan Limit
#define SCANLMTDIG6      0x0B06 //Scan Limit
#define SCANLMTDIG7      0x0B07 //Scan Limit

#define SHTDWNON    0x0C00 //shutdown all LEDs
#define SHTDWNOFF     0x0C01 //shutdown all LEDs

class MAX7219
{
	public:
		MAX7219(SPI_TypeDef *spi, uint16_t pins);

	private:
		SPI_TypeDef *SPIx;
};

#endif /* MAX7219_H_ */
