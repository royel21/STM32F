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
  uint8_t head = 1;
  uint8_t tail = 1;
  while (1)
  {
    Serial2.println("H:", 350);
  }
  return 0;
}
