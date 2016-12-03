
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

  //spi.setBidiMode(SPI_TRANSMIT);
//  Serial2.Init(115200);
//  spi.softPin(GPIOA, P04);
//  spi.start(SPI_BRRDIV16);
//
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

//	uint8_t data[] =
//	{ 0, 0, 0, 0, 0, 0, 0, 0 };
//	matrix.writeData(data);
//	matrix.setDisplayON(ON);
//	matrix.setScanDigit(8);
//	matrix.setBrightness(15);
//  delayMillis(1000);
//  sendData(0x0A0F);
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
  LCD_I2C lcd(0x27);
  lcd.Init();
  while (1)
  {
    lcd.print("hola Mundo");
    delayMillis(100);
//    if (Serial2.hasData())
//    {
//
//      char ch = Serial2.readByte();
//      switch (ch)
//      {
//        case 'a':
//        {
//          Serial2.print("ALLON:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x0F01);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case 'b':
//        {
//          Serial2.print("ALLOFF:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x0F00);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case 'c':
//        {
//          Serial2.print("BrightLow:");
//          for (int i = 0; i < 8; i++)
//          {
//            spi.chipSelect(LOW);
//            spi.send16Byte(max[i]);
//            spi.chipSelect(HIGH);
//            //delayMicros(500);
//            Serial2.println("Data:", max[i], HEX);
//          }
//
//          break;
//        }
//        case 'd':
//        {
//          Serial2.print("BrightHigh:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0xA0f);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case 'e':
//        {
//          Serial2.print("Scan8Digit:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x0B07);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case 'f':
//        {
//          Serial2.print("on:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x0C01);
//          spi.chipSelect(HIGH);
//          break;
//        }
//
//        case '1':
//        {
//          Serial2.print("BrightLow:");
//          for (int i = 0; i < 8; i++)
//          {
//            spi.chipSelect(LOW);
//            spi.send16Byte(max2[i]);
//            spi.chipSelect(HIGH);
//            //delayMicros(500);
//            Serial2.println("Data:", max[i], HEX);
//          }
//          break;
//        }
//        case '2':
//        {
//          Serial2.print("Row2:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x02FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case '3':
//        {
//          Serial2.print("Row3:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x03FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case '4':
//        {
//          Serial2.print("Row4:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x04FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case '5':
//        {
//          Serial2.print("Row5:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x05FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case '6':
//        {
//          Serial2.print("Row6:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x06FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case '7':
//        {
//          Serial2.print("Row7:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x07FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//        case '8':
//        {
//          Serial2.print("Row8:");
//          spi.chipSelect(LOW);
//          spi.send16Byte(0x08FF);
//          spi.chipSelect(HIGH);
//          break;
//        }
//
//      }
//      Serial2.WriteByte(ch);
//     Serial2.WriteByte('\n');
//
//    }
  }
  return 0;
}

