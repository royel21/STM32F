/*
 * LCDI2C.cpp
 *
 *  Created on: Jun 29, 2016
 *      Author: RoyerAriel
 */

#include "LCDI2C.h"

LCD_I2C::LCD_I2C(uint8_t addr)
{
	address = addr;
	cmd = 0x0C;
  blackLightState = 0x08;
}

void LCD_I2C::Init()
{
	Write4Bits(0x80);
  delayMillis(15);
	Write4Bits(0x30);
  delayMicros(1000);
	Write4Bits(0x30);
  delayMicros(1000);
	Write4Bits(0x30);
  delayMicros(150);
	Write4Bits(0x20);
	WriteCmd(LCD_FUNCTIONSET | LCD_4BITMODE | LCD_2LINE | LCD_5x8DOTS);

	WriteCmd(LCD_DISPLAYCONTROL | LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF);
	Clear(); /// LCD CLEAR
	WriteCmd(LCD_ENTRYMODESET | LCD_ENTRYLEFT);   //LCD DISAPLY FUCTIO

}
void LCD_I2C::Write4Bits(uint8_t data)
{
  I2C1Comm.WriteTo(address, data | EnON | blackLightState);
  delayMicros(1);
  I2C1Comm.WriteTo(address, (data | blackLightState) & ~EnON);
  delayMicros(40);
}

void LCD_I2C::WriteByte(const char data)
{
	uint8_t high = data & 0xf0;
	uint8_t low = (data << 4) & 0xf0;
	Write4Bits(high | RsData);
	Write4Bits(low | RsData);
}
void LCD_I2C::WriteCmd(uint8_t data)
{
	uint8_t high = data & 0xf0;
	uint8_t low = (data << 4) & 0xf0;
	Write4Bits(high | RsCmd);
	Write4Bits(low | RsCmd);
}

void LCD_I2C::CursorPos(uint8_t col, uint8_t row)
{
	int row_offsets[4] = { 0x00, 0x40, 0x14, 0x54 };
	WriteCmd(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}
void LCD_I2C::Cursor(uint8_t state)
{
	cmd |= state << 1;
	WriteCmd(cmd);
}
void LCD_I2C::autoScroll(uint8_t on)
{
	if (on)
	{
		WriteCmd(LCD_ENTRYMODESET | LCD_ENTRYSHIFTINCREMENT);
	} else
	{
		WriteCmd(LCD_ENTRYMODESET);
	}
}
void LCD_I2C::blackLight(const uint8_t state)
{
	blackLightState = state << 3;
	I2C1Comm.WriteTo(address, blackLightState);
}
void LCD_I2C::Clear()
{
	WriteCmd(LCD_CLEARDISPLAY);
  delayMillis(2);
}

