#include "SerialHardware.h"
#include "Timer.h"
#include "Analog.h"
#include "I2CSerialComm.h"

int main(void)
{
	Serial2.Init(921600);
	Serial2.setEndCode('\r');
	GPIO_Config(GPIOC, P08 | P09 | P05, MODE_OUT, PULL_UP, OTYPER_PP, SPEED_100MHz);

	while (1)
	{
		delayMillis(100);
	}
	return 0;
}
