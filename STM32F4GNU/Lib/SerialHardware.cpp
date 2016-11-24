/*
 * SerialHardware.cpp
 *
 *  Created on: Jun 8, 2016
 *      Author: RoyerAriel
 */

#include "SerialHardware.h"
#include "misc.h"
int i = 0;
SerialHardware::SerialHardware(GPIO_TypeDef *port, uint16_t pins, uint8_t AF_Func)
{
  ITStatus = 0;
  endCode = 0x00;
  head = 0;
  tail = 0;
//	buffIndex = 0;

//	userBuff = 1;
#ifdef USE_USART1
  if(AF_Func == AF_USART1)
  {
    USARTx = USART1;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
    usartClock = SystemCoreClock;
  }
#endif

#ifdef USE_USART2
  if (AF_Func == AF_USART2)
  {
    USARTx = USART2;
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
    usartClock = SystemCoreClock / 2;
  }
#endif

#ifdef USE_USART3
  if(AF_Func == AF_USART3)
  {
    USARTx = USART3;
    RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
    usartClock = SystemCoreClock/2;
  }
#endif

#ifdef USE_USART6
  else if(AF_Func == AF_USART6)
  {
    USARTx = USART6;
    RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
    usartClock = SystemCoreClock;
  }
}
#endif
  GPIO_Config(port, pins, MODE_AF, PULL_NO, OTYPER_PP, SPEED_100MHz, AF_Func);
}
void SerialHardware::setEndCode(char code)
{
  endCode = code;
}
void SerialHardware::EnableIT(IRQn_Type usart, uint16_t it, FunctionalState state)
{
  ITStatus = 1;
  //USARTx->
  USARTx->CR1 |= USART_CR1_RXNEIE;
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = it;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = state;
  NVIC_Init(&NVIC_InitStructure);
  NVIC_EnableIRQ(usart);
}
void SerialHardware::Init(uint32_t brr)
{
  USARTx->CR1 |= USART_CR1_TE | USART_CR1_RE;

  uint32_t tmpBRR = 0;
  uint32_t intDV = 0;
  uint32_t fracDV = 0;
  /* Integer part computing in case Oversampling mode is 16 Samples */
  intDV = ((25 * usartClock) / (4 * brr));
  //* Determine the integer part */ (4 * (brr)))
  tmpBRR = (intDV / 100) << 4;
  /* Determine the fractional part */
  fracDV = intDV - (100 * (tmpBRR >> 4));

  tmpBRR |= ((((fracDV * 16) + 50) / 100)) & ((uint8_t) 0x0F);

  USARTx->BRR = tmpBRR;

  USARTx->CR1 |= USART_CR1_UE; // USART ENABLE
}

void SerialHardware::WriteByte(const char byte)
{
  while (!(USARTx->SR & USART_SR_TXE))
    ;
  USARTx->DR = byte;
}

char SerialHardware::readByte()
{
  if (!ITStatus)
  {
    while (!(USARTx->SR & USART_SR_RXNE))
      ;
    return (USARTx->DR & 0xFF);
  } else
  {
    if (tail == head)
      return -1;

    tail = (tail + 1) % BUFFSIZE;
    return buff[tail];
  }
}

void SerialHardware::receiveByteIT()
{
  uint8_t ch = (USARTx->DR & 0xFF);
  uint8_t next = (head + 1) % BUFFSIZE;
  if (next != tail)
  {
    buff[next] = ch;
    head = next;
  }
}
void SerialHardware::println(char var)
{
  WriteByte(var);
  WriteByte('\n');
}

void SerialHardware::println(int var, uint8_t base)
{
  println((int32_t) var, base);
}

void SerialHardware::println(int32_t var, uint8_t base)
{
  print(var, base);
  WriteByte('\n');
}

void SerialHardware::println(uint32_t var, uint8_t base)
{
  print(var, base);
  WriteByte('\n');
}

void SerialHardware::println(double var)
{
  print(var);
  WriteByte('\n');
}

void SerialHardware::println(const char *str)
{
  print(str);
  WriteByte('\n');
}
void SerialHardware::println(const char *str, int var, uint8_t base)
{
  println(str, (int32_t) var, base);
}

void SerialHardware::println(const char *str, int32_t var, uint8_t base)
{
  print(str);
  print(var, base);
  WriteByte('\n');
}

void SerialHardware::println(const char *str, uint32_t var, uint8_t base)
{
  print(str);
  print(var, base);
  WriteByte('\n');
}

void SerialHardware::println(const char *str, double var)
{
  print(str);
  print(var);
  WriteByte('\n');
}

#ifdef USE_USART1
SerialHardware Serial1(GPIOA, P09, P10, AF_P09, AF_P10, AF_USART1);
extern "C" void USART1_IRQHandler()
{
  if (USART1->SR & USART_SR_RXNE)
  {
    Serial1.receiveByteIT();
  }
}
#endif

#ifdef USE_USART2
SerialHardware Serial2(GPIOA, P02 | P03, AF_USART2);
extern "C" void USART2_IRQHandler()
{
  if (USART2->SR & USART_SR_RXNE)
  {
    Serial2.receiveByteIT();
  }
}
#endif

#ifdef USE_USART3
SerialHardware Serial3(GPIOA, P02 | P03, AF_USART3);
extern "C" void USART3_IRQHandler()
{
  if (USART3->SR & USART_SR_RXNE)
  {
    Serial3.receiveByteIT();
  }
}
#endif

#ifdef USE_USART6
SerialHardware Serial6(GPIOC, P06, P07, AF_P06, AF_P07, AF_USART6);

extern "C" void USART6_IRQHandler()
{
  if (USART6->SR & USART_SR_RXNE)
  {
    Serial6.receiveByteIT();
  }
}
#endif

