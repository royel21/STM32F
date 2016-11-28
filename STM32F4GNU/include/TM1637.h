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

#include <cmsis_device.h>.h>
#include "util.h"
#include "Timer.h"

#define SEG_A   0b00000001
#define SEG_B   0b00000010
#define SEG_C   0b00000100
#define SEG_D   0b00001000
#define SEG_E   0b00010000
#define SEG_F   0b00100000
#define SEG_G   0b01000000

class TM1637
{

	public:
		//! Initialize a TM1637 object, setting the clock and
		//! data pins.
		//!
		//! @param pinClk - The number of the digital pin connected to the clock pin of the module
		//! @param pinDIO - The number of the digital pin connected to the DIO pin of the module
		TM1637(GPIO_TypeDef *port, uint16_t clock, uint16_t dio);

		//! Sets the brightness of the display.
		//!
		//! The setting takes effect when a command is given to change the data being
		//! displayed.
		//!
		//! @param brightness A number from 0 (lowes brightness) to 7 (highest brightness)
		void setBrightness(uint8_t brightness);

		//! Display arbitrary data on the module
		//!
		//! This function receives raw segment values as input and displays them. The segment data
		//! is given as a byte array, each byte corresponding to a single digit. Within each byte,
		//! bit 0 is segment A, bit 1 is segment B etc.
		//! The function may either set the entire display or any desirable part on its own. The first
		//! digit is given by the @ref pos argument with 0 being the leftmost digit. The @ref length
		//! argument is the number of digits to be set. Other digits are not affected.
		//!
		//! @param segments An array of size @ref length containing the raw segment values
		//! @param length The number of digits to be modified
		//! @param pos The position from which to start the modification (0 - leftmost, 3 - rightmost)
		void setSegments(const uint8_t segments[], uint8_t length = 4, uint8_t pos = 0);

		//! Displayes a decimal number
		//!
		//! Dispalyes the given argument as a decimal number
		//!
		//! @param num The number to be shown
		//! @param leading_zero When true, leading zeros are displayed. Otherwise unnecessary digits are
		//!        blank
		//! @param length The number of digits to set. The user must ensure that the number to be shown
		//!        fits to the number of digits requested (for example, if two digits are to be displayed,
		//!        the number must be between 0 to 99)
		//! @param pos The position least significant digit (0 - leftmost, 3 - rightmost)
		void showNumberDec(int num, bool leading_zero = false, uint8_t length = 4, uint8_t pos = 0);

		//! Translate a single digit into 7 segment code
		//!
		//! The method accepts a number between 0 - 15 and converts it to the
		//! code required to display the number on a 7 segment display.
		//! Numbers between 10-15 are converted to hexadecimal digits (A-F)
		//!
		//! @param digit A number between 0 to 15
		//! @return A code representing the 7 segment image of the digit (LSB - segment A;
		//!         bit 6 - segment G; bit 7 - always zero)
		uint8_t encodeDigit(uint8_t digit);

	private:
		void start();

		void stop();

		bool writeByte(uint8_t b);
		GPIO_TypeDef *PORT;
		uint8_t CLOCK;
		uint8_t DIO;
		uint8_t brightness;

};

#endif // __TM1637__
