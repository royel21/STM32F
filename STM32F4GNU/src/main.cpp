#include <cmsis_device.h>
#include "SerialHardware.h"
#include "Timer.h"
#include "LCDI2C.h"
#include "I2CSerialComm.h"
#include "SPI.h"

int main(void)
{
  //Init_Timer();
  //SerialHardware Serial2(USART2, GPIOA, P01 | P02, GPIO_AF_USART2);
  // TIM_PWM_Init(68);
  LCD_I2C lcd(0x27);
  lcd.Init();
  lcd.print("hi");
  lcd.print("hi");
  lcd.print("hi");
  Serial2.Init(460800);
  Serial2.setEndCode('\r');
  //Serial2.println('A');
  //Serial2.EnableIT(USART2_IRQn, USART_CR1_RXNEIE, ENABLE);
  //Serial2.println('A');
  //long a = 1410545456;
  //Serial2.print("long:", a);
  //Serial2.println("long:", a);
  uint8_t x = 0;
  while (1)
  {
    lcd.CursorPos(2, 1);
    lcd.print("world wide:", x);
    x++;
//    if (Serial2.hasData())
//    {
//      Serial2.print(Serial2.readByte());
//    }
    // Serial2.println(Serial2.hasData());
    //Serial2.println('A');
    Serial2.WriteByte('A');
    //Serial2.println('m');
    delayMillis(100);
    //if (Serial2.hasData())
    // Serial2.print(Serial2.readByte(), HEX);
    // Serial2.println("TEST:");
  }
  return 0;
}
