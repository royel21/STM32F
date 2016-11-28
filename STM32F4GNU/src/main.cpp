#include <cmsis_device.h>
#include "SerialHardware.h"
#include "Timer.h"
#include "LCDI2C.h"
#include "I2CSerialComm.h"
#include "Analog.h"

int main(void)
{
  //Init_Timer();
  //SerialHardware Serial2(USART2, GPIOA, P01 | P02, GPIO_AF_USART2);
  // TIM_PWM_Init(68);

  // Serial2.Init(38400);
  // Serial2.setEndCode('\r');
  Serial2.Init(921600);
  Serial2.setEndCode('\r');
  Serial6.Init(921600);
  Serial6.setEndCode('\r');
  //Serial2.println('A');
  //Serial2.EnableIT(USART2_IRQn, USART_CR1_RXNEIE, ENABLE);
  //Serial2.println('A');
  //long a = 1410545456;
  //Serial2.print("long:", a);
  //Serial2.println("long:", a);

  while (1)
  {

    //Serial6.println("test");
    if (Serial2.hasData())
    {
      Serial6.println(analogRead(0));
      Serial6.WriteByte(Serial2.readByte());
    }
    //Serial2.println(Serial2.readByte());
    if (Serial6.hasData())
    {
      Serial2.WriteByte(Serial6.readByte());
    }
  }
  return 0;
}
