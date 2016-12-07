#include "SPI.h"
#include "MAX7219.h"
#include "Timer.h"
#include "SerialHardware.h"
#include "LCDI2C.h"
#include "I2CSerialComm.h"

SPI spi(SPI1, P05 | P06 | P07);
const uint16_t max[] =
  { 0x0118, 0x023C, 0x037E, 0x04DB, 0x05FF, 0x0624, 0x075A, 0x08A5 };
const uint16_t max2[] =
  { 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600, 0x0700, 0x0800 };

void sendData(uint16_t data)
{
  spi.chipSelect(LOW);
  spi.send16Byte(data);
  spi.chipSelect(HIGH);
}

int main(void)
{

//  spi.setBidiMode(SPI_TRANSMIT);
  Serial2.Init(115200);
  spi.softPin(GPIOA, P04);
  spi.start(SPI_BRRDIV16);

//  MAX7219 matrix(&spi);
//	spi.slaveSelect(LOW);
//	spi.send16Byte(0x0B07);
//	spi.slaveSelect(HIGH);
//
//	delayMillis(100);
//
//	Serial2.println("BrightLow:");
//
//	spi.slaveSelect(LOW);
//	spi.send16Byte(0x0A0F);
//	spi.slaveSelect(HIGH);
//
//	Serial2.println("on:");
//
//	spi.slaveSelect(LOW);
//	spi.send16Byte(0x0C01);
//	spi.slaveSelect(HIGH);
//
//	delayMillis(100);
//
//	uint8_t data[] =
//	{ 0, 0, 0, 0, 0, 0, 0, 0 };
//	matrix.writeData(data);
//	matrix.setDisplayON(ON);
//	matrix.setScanDigit(8);
//	matrix.setBrightness(15);
//  delayMillis(1000);

//  for (int i = 0; i < 8; i++)
//  {
//
//    //sendData(0x0A0F);
//    //sendData(0x0B07);
//
//    sendData(0x0B07);
//    delayMillis(250);
//    sendData(0x0C01);
//    sendData(max2[i]);
//    //delayMicros(20);
//  }
//
//  for (int i = 0; i < 8; i++)
//  {
//
//    //sendData(0x0A0F);
//    //sendData(0x0B07);
//    sendData(0x0B07);
//    sendData(0x0C01);
//    sendData(max[i]);
//    delayMillis(250);
//  }
  uint8_t bright = 8;
  while (1)
  {

    if (Serial2.hasData())
    {

      char ch = Serial2.readByte();
      switch (ch)
      {
        case 'a':
        {
          Serial2.print("ALLON:");
          sendData(0x0F01);
          break;
        }
        case 'b':
        {
          Serial2.print("ALLOFF:");
          sendData(0x0F00);
          break;
        }
        case 'c':
        {
          Serial2.print("BrightLow:");
          for (int i = 0; i < 8; i++)
          {
            sendData(max[i]);
          }

          break;
        }
        case 'd':
        {
          Serial2.print("BrightHigh:");
          sendData(0xA00 | bright);
          break;
        }
        case 'e':
        {
          Serial2.print("Scan8Digit:");
          sendData(0x0B07);
          break;
        }
        case 'f':
        {
          Serial2.print("on:");
          sendData(0x0C01);
          break;
        }

        case '0':
        {
          Serial2.print("BrightLow:");
          for (int i = 0; i < 8; i++)
          {
            sendData(max2[i]);
          }
          break;
        }
        case '1':
        {
          sendData(0x01018);
          break;
        }
        case '2':
        {
          sendData(0x0203C);
          break;
        }
        case '3':
        {
          sendData(0x037E);
          break;
        }
        case '4':
        {
          sendData(0x047E);
          break;
        }
        case '5':
        {
          sendData(0x053C);
          break;
        }
        case '6':
        {
          sendData(0x0618);
          break;
        }
        case '7':
        {
          Serial2.print("Row7:");
          sendData(0x07FF);
          break;
        }
        case '8':
        {
          Serial2.print("Row8:");
          sendData(0x08FF);
          break;
        }
        case '+':
        {
          if (bright < 0xF)
          {
            sendData(0x0A00 | ++bright);
          }
          break;
        }
        case '-':
        {
          if (bright > 0x00)
          {
            sendData(0x0A00 | --bright);
          }

          break;
        }
      }
      Serial2.WriteByte(ch);
      Serial2.WriteByte('\n');

    }
  }
  return 0;
}

