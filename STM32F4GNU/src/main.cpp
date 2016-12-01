#include "SPI.h"
#include "MAX7219.h"
#include "Timer.h"
#include "SerialHardware.h"
int main(void)
{
	SPI spi(SPI1, P05 | P06 | P07);
	//spi.setBidiMode(SPI_TRANSMIT);
	Serial2.Init(115200);
	spi.softPin(GPIOA, P04);
	spi.start(SPI_BRRDIV16);

	while (1)
	{
		if (Serial2.hasData())
		{

			char ch = Serial2.readByte();
			switch (ch)
			{
				case '1':
				{
					Serial2.println("0x0900:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x0900);
					spi.slaveSelect(HIGH);
					break;
				}
				case '2':
				{
					Serial2.println("0A00:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x0A00);
					spi.slaveSelect(HIGH);
					break;
				}
				case '3':
				{
					Serial2.println("0x0B00:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x0B00);
					spi.slaveSelect(HIGH);
					break;
				}
				case '4':
				{
					Serial2.println("0x0C01:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x0C01);
					spi.slaveSelect(HIGH);
					break;
				}
				case '5':
				{
					Serial2.println("0x01AA:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x01AA);
					spi.slaveSelect(HIGH);
					break;
				}
				case '6':
				{
					Serial2.println("0x0155:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x0155);
					spi.slaveSelect(HIGH);
					break;
				}
				case '7':
				{
					Serial2.println("0x0177:");
					spi.slaveSelect(LOW);
					spi.send16Byte(0x0177);
					spi.slaveSelect(HIGH);
					break;
				}
					Serial2.WriteByte(ch);
			}

		}
	}
	return 0;
}

