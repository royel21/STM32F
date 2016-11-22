/*
 * SerialHardware.cpp
 *
 *  Created on: Jun 8, 2016
 *      Author: RoyerAriel
 */

#include "SerialHardware.h"

SerialHardware::SerialHardware(USART_TypeDef *USARTy, GPIO_TypeDef *port, uint16_t pins,
    uint8_t AF_pin)
{
  ITStatus = 0;
	endCode = 0x00;
  head = 0;
  tail = 0;
//	buffIndex = 0;
	USARTx = USARTy;
//	userBuff = 1;
#ifdef USE_USART1
	if(USARTx == USART1)
	{
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
	}
#endif

#ifdef USE_USART2
	if (USARTx == USART2)
	{
    RCC->APB1ENR |= RCC_APB1ENR_USART2EN;
	}
#endif

#ifdef USE_USART3
	if(USARTx== USART3)
	{
    RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
	}
#endif

#ifdef USE_USART6
	else if(USARTx== USART6)
	{
    RCC->APB2ENR |= RCC_APB2ENR_USART6EN;
	}
}
#endif
  GPIO_Config(port, pins, MODE_AF, PULL_NO, OTYPER_PP, SPEED_100MHz, AF_pin);
}
void SerialHardware::setEndCode(char code)
{
	endCode = code;
}
void SerialHardware::EnableIT(IRQn_Type usart, uint16_t it,
		FunctionalState state)
{
  ITStatus = 1;
  //USARTx->
  USARTx->CR1 |= it;
	IT_Init(usart, 0, 0, state);
}
void SerialHardware::Init(uint32_t brr)
{
	USART_InitTypeDef tUSART;
	tUSART.USART_BaudRate = brr;
	tUSART.USART_WordLength = USART_WordLength_8b;
	tUSART.USART_StopBits = USART_StopBits_1;
	tUSART.USART_Parity = USART_Parity_No;
	tUSART.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	tUSART.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
	USART_Init(USARTx, &tUSART);
	USARTx->CR1 |= USART_CR1_UE; // USART ENABLE
}

void SerialHardware::WriteByte(const char byte)
{
	while (!(USARTx->SR & USART_SR_TXE))
		;
	USARTx->DR = byte;
}


uint8_t SerialHardware::readByte()
{
  if (!ITStatus)
  {
	while (!(USARTx->SR & USART_FLAG_RXNE))
		;
	return (USARTx->DR & 0xFF);
  } else
  {
    if (head == tail)
      return 255;

    uint8_t ch = buff[tail];
    tail = (tail + 1) % BUFFSIZE;

    return ch;
  }
}

void SerialHardware::receiveByteIT()
{
	uint8_t ch = (USARTx->DR & 0xFF);
  uint8_t next = (head + 1) % BUFFSIZE;
  if (head != tail)
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
SerialHardware Serial1(USART1, GPIOA, P09, P10, AF_P09, AF_P10, AF_USART1);
extern "C" void USART1_IRQHandler()
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		Serial1.receiveByte();
	}
}
#endif

#ifdef USE_USART2
SerialHardware Serial2(USART2, GPIOA, P02 | P03, GPIO_AF_USART2);
extern "C" void USART2_IRQHandler()
{
	if (USART_GetITStatus(USART2, USART_IT_RXNE))
	{
		Serial2.receiveByteIT();
	}
}
#endif

#ifdef USE_USART3
SerialHardware Serial3(USART2, GPIOA, P02 | P03, GPIO_AF_USART2);
extern "C" void USART3_IRQHandler()
{
	if (USART_GetITStatus(USART2, USART_IT_RXNE))
	{
		//Serial2.receiveByteIT();
	}
}
#endif

#ifdef USE_USART6
SerialHardware Serial6(USART2, GPIOC, P06, P07, AF_P06, AF_P07, AF_USART6);

extern "C" void USART6_IRQHandler()
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		Serial6.receiveByte();
	}
}
#endif

