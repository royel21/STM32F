#include <cmsis_device.h>
#include "SerialHardware.h"
#include "Timer.h"
#include "LCDI2C.h"

#define SIZE 2
volatile uint16_t ADCConvertedValues[2];
//int ConvertedValue = 0; //Converted value readed from ADC


int main(void)
{
  //Init_Timer();
  //SerialHardware Serial2(USART2, GPIOA, P01 | P02, GPIO_AF_USART2);
  // TIM_PWM_Init(68);

  Serial2.Init(115200);
  Serial2.setEndCode('\r');
  Serial2.println('A');
  Serial2.EnableIT(USART2_IRQn, USART_IT_RXNE, ENABLE);
  Serial2.println('A');
  long a = 1410545456;
  Serial2.print("long:", a);
  Serial2.println("long:", a);
  while (1)
  {
    if (Serial2.hasData())
    {
      Serial2.print(Serial2.readByte());
    }

    // Serial2.println('A');
    //Serial2.println('m');
    // delayMillis(1);
    //if (Serial2.hasData())
    // Serial2.print(Serial2.readByte(), HEX);
    // Serial2.println("TEST:");
  }
  return 0;
}
