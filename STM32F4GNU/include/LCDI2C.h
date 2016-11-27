/*
 * LCDI2C.h
 *
 *  Created on: Jun 29, 2016
 *      Author: RoyerAriel
 */

#ifndef LCDI2C_H_
#define LCDI2C_H_

#include "I2CSerialComm.h"
#include "Timer.h"
#include "LCDConfig.h"
#include "define.h"
#include "Printer.h"

class LCD_I2C: public Printer
{
	private:
		uint8_t cmd;
		uint8_t blackLightState;
		uint8_t address;
		void pulseEnable();
		void Write4Bits(uint8_t);
	public:

    LCD_I2C(uint8_t);

		void WriteByte(const char);

    void Init();
		void WriteCmd(uint8_t);

		void Clear();
		void Cursor(uint8_t);
		void Blink();
		void CursorPos(uint8_t, uint8_t);
		void autoScroll(uint8_t);
		void blackLight(const uint8_t);
};

#endif /* LCDI2C_H_ */
