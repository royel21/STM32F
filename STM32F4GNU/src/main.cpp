#include "SerialHardware.h"
#include "Timer.h"
#include "Analog.h"
#include "I2CSerialComm.h"
#include "TM1637.h"

int main(void)
{
	TM1637 tm1637(GPIOA, P00, P01);
	tm1637.setBrightness(0x09);
	uint8_t data[] =
	{ 0, 0, 0, 0 };

	//GPIO_Config(GPIOA, P00 | P01, MODE_OUT, PULL_UP, OTYPER_PP, SPEED_100MHz);
	tm1637.setSegments(data);
	int num = 0;
	uint8_t dot = DOTON;
	while (1)
	{
		tm1637.showNumberDec(num++, dot);
		dot = ~dot;
		delayMillis(1000);
	}
	return 0;
}

