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

#include "TM1637.h"

#define delayck   delayMicros(10)

#define CMD1    (uint8_t)0x44
#define CMD2    (uint8_t)0xC0
#define CMD3    (uint8_t)0x80

const uint8_t segm[] =
{ 0x3F,   // 0
		0x06,   // 1
		0x5B,   // 2
		0x4F,   // 3
		0x66,   // 4
		0x6D,   // 5
		0x7D,   // 6
		0x07,   // 7
		0x7F,   // 8
		0x6F,   // 9
		0x77,   // A
		0x7C,   // B
		0x29,   // C
		0x5E,   // D
		0x79,   // E
		0x71    // F
		};

TM1637::TM1637(GPIO_TypeDef *port, uint16_t clock, int16_t dio)
{
	PORT = port;
	brightness = 0;
	CLOCK = clock;
	DIO = dio;
	// Set the pin direction and default value.
	// Both pins are set as inputs, allowing the pull-up resistors to pull them up
	GPIO_Config(port, clock | dio, MODE_OUT, PULL_UP, OTYPER_OD, SPEED_100MHz);
	PORT->BSRRL = DIO | CLOCK;
}

void TM1637::writeByte(uint8_t data)
{

	// 8 Data Bits
	for (uint8_t i = 0; i < 8; i++)
	{
		// CLK low
		PORT->BSRRH = CLOCK;
		delayck;
		// Set data bit
		if (data & 0x01)
			PORT->BSRRL = DIO;
		else
			PORT->BSRRH = DIO;
		delayck;
		// CLK high
		PORT->BSRRL = CLOCK;
		delayck;
		data = data >> 1;
	}
	// Wait for acknowledge
	// CLK to zero
	PORT->BSRRH = CLOCK;
	PORT->BSRRL = DIO;
	delayck;
	// CLK to high
	PORT->BSRRL = CLOCK;
	delayck;
	if ((PORT->IDR & DIO) == 0)
		PORT->BSRRH = DIO;

	delayck;
	PORT->BSRRH = CLOCK;
	delayck;
}

void TM1637::start()
{
	PORT->BSRRH = DIO;
	delayck;
}

void TM1637::stop()
{
	PORT->BSRRH = DIO;
	delayck;
	PORT->BSRRL = CLOCK;
	delayck;
	PORT->BSRRL = DIO;
	delayck;
}

void TM1637::setLight(uint8_t brightness)
{
	this->brightness = brightness;
}

void TM1637::setSegs(const uint8_t *segs, uint8_t d)
{
	for (uint8_t i = 0; i < 4; i++)
		setSegs(segs[i], i + 1, d);
}
void TM1637::setSegs(const uint8_t segs, uint8_t pos, uint8_t d)
{
	// Write COMM1
	start();
	writeByte(CMD1);
	stop();

	// Write COMM2 + first digit address
	start();
	writeByte(CMD2 + ((3 - (pos - 1)) & (uint8_t) 0x03));

	// Write the data bytes
	writeByte(segm[segs] | (d << 7));

	stop();

	// Write COMM3 + brightness
	start();
	writeByte(CMD3 + (brightness & (uint8_t) 0x0f));
	stop();
}

void TM1637::print(int num, uint8_t d)
{
	uint8_t digits[4] =
	{ 0, 0, 0, 0 };
	int i = 0;
	do
	{
		digits[i++] = (num % 10); //integer to ANSI
		num /= 10;
	} while (num);
	setSegs(digits, d);
}

