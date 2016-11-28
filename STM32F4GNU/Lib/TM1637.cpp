
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

#define TM1637_I2C_COMM1    0x40
#define TM1637_I2C_COMM2    0xC0
#define TM1637_I2C_COMM3    0x80

//
//      A
//     ---
//  F |   | B
//     -G-
//  E |   | C
//     ---
//      D
const uint8_t digitToSegment[] = {
 // XGFEDCBA
  0b00111111,    // 0
  0b00000110,    // 1
  0b01011011,    // 2
  0b01001111,    // 3
  0b01100110,    // 4
  0b01101101,    // 5
  0b01111101,    // 6
  0b00000111,    // 7
  0b01111111,    // 8
  0b01101111,    // 9
  0b01110111,    // A
  0b01111100,    // b
  0b00111001,    // C
  0b01011110,    // d
  0b01111001,    // E
  0b01110001     // F
  };


TM1637::TM1637(GPIO_TypeDef *port, uint16_t clock, uint16_t dio)
{
	PORT = port;
	brightness = 0;
	CLOCK = clock;
	DIO = dio;

	// Set the pin direction and default value.
	// Both pins are set as inputs, allowing the pull-up resistors to pull them up
	GPIO_Config(port, clock | dio, MODE_OUT, PULL_UP, OTYPER_PP, SPEED_100MHz);
}

void TM1637::setBrightness(uint8_t brightness)
{
	this->brightness = brightness;
}

void TM1637::setSegments(const uint8_t segments[], uint8_t length, uint8_t pos)
{
    // Write COMM1
	start();
	writeByte(TM1637_I2C_COMM1);
	stop();

	// Write COMM2 + first digit address
	start();
	writeByte(TM1637_I2C_COMM2 + (pos & 0x03));

	// Write the data bytes
	for (uint8_t k = 0; k < length; k++)
	  writeByte(segments[k]);

	stop();

	// Write COMM3 + brightness
	start();
	writeByte(TM1637_I2C_COMM3 + (brightness & 0x0f));
	stop();
}

void TM1637::showNumberDec(int num, bool leading_zero, uint8_t length, uint8_t pos)
{
	uint8_t digits[4];
	const static int divisors[] = { 1, 10, 100, 1000 };
	bool leading = true;

	for(int8_t k = 0; k < 4; k++) {
	    int divisor = divisors[4 - 1 - k];
		int d = num / divisor;

		if (d == 0) {
		  if (leading_zero || !leading || (k == 3))
		    digits[k] = encodeDigit(d);
	      else
		    digits[k] = 0;
		}
		else {
			digits[k] = encodeDigit(d);
			num -= d * divisor;
			leading = false;
		}
	}

	setSegments(digits + (4 - length), length, pos);
}

void TM1637::start()
{
	PORT->ODR ^= CLOCK | DIO;
	delayMicros(5);
	PORT->ODR ^= CLOCK;
}

void TM1637::stop()
{
//	pinMode(m_pinDIO, OUTPUT);
//	delayMicros(5);
//	pinMode(m_pinClk, INPUT);
//	delayMicros(5);
//	pinMode(m_pinDIO, INPUT);
//	delayMicros(5);
}

bool TM1637::writeByte(uint8_t b)
{
  uint8_t data = b;

  // 8 Data Bits
//  for(uint8_t i = 0; i < 8; i++) {
//    // CLK low
//    pinMode(m_pinClk, OUTPUT);
//		delayMicros(5);
//
//	// Set data bit
//    if (data & 0x01)
//      pinMode(m_pinDIO, INPUT);
//    else
//      pinMode(m_pinDIO, OUTPUT);
//
//		delayMicros(5);
//
//	// CLK high
//    pinMode(m_pinClk, INPUT);
//		delayMicros(5);
//    data = data >> 1;
//  }
//
//  // Wait for acknowledge
//  // CLK to zero
//  pinMode(m_pinClk, OUTPUT);
//  pinMode(m_pinDIO, INPUT);
//	delayMicros(5);
//
//  // CLK to high
//  pinMode(m_pinClk, INPUT);
//	delayMicros(5);
//  uint8_t ack = digitalRead(m_pinDIO);
//  if (ack == 0)
//    pinMode(m_pinDIO, OUTPUT);
//
//
//  delayMicros(5);
//  pinMode(m_pinClk, OUTPUT);
//	delayMicros(5);

	return 1;
}

uint8_t TM1637::encodeDigit(uint8_t digit)
{
	return digitToSegment[digit & 0x0f];
}



