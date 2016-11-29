#include "Timer.h"
#include "TM1637.h"

int main(void)
{
	TM1637 tm1637(GPIOC, P00, P01);
	tm1637.setLight(MEDLIGHT);
//	uint8_t data[] =
//	{ 1, 2, 3, 4 };
//	tm1637.setSegs(data, DOTON);
	int num = 10;
	uint8_t dot = 1;
	while (1)
	{
		tm1637.print(num++, dot);
		dot = ~dot;
		delayMillis(1000);
	}
	return 0;
}

