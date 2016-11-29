/*
 * TM1637.h
 *
 *  Created on: Nov 28, 2016
 *      Author: RoyerAriel
 */

//  Author: avishorp@gmail.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef __TM1637__
#define __TM1637__

#include <cmsis_device.h>
#include "util.h"
#include "Timer.h"

#define DOTON  (uint8_t)0x80
#define DOTOFF (uint8_t)0x7f
class TM1637
{

	public:
		TM1637(GPIO_TypeDef *port, uint16_t clock, int16_t dio);
		void setBrightness(uint8_t brightness);
		void setSegments(const uint8_t seg, uint8_t pos = 3);
		void setSegments(const uint8_t *segs, uint8_t pos = 0);
		void showNumberDec(int num, uint8_t dot = 0);

	private:
		void start();
		void stop();
		void writeByte(uint8_t b);
		GPIO_TypeDef *PORT;
		uint8_t CLOCK;
		uint8_t DIO;
		uint8_t brightness;
		uint8_t dots;

};

#endif // __TM1637__
