/*
 * Util.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: RoyerAriel
 */
#include "Util.h"
/*
 * 1:GPIO PORT
 * 2:GPIO ORE PINS PXX | PXX
 * 3:GPIO Mode MODE_XX
 * 4:GPIO PUSH Resistor PUSH_XX
 * 5:GPIO OUTPUT Type OTYPER_XX
 * 6:GPIO SPEED
 *
 */
void GPIO_Config(GPIO_TypeDef *port, const uint16_t pins, uint8_t mode, uint8_t pushpull,
    uint8_t oTyper, uint8_t speed, uint8_t af)
{
  if (port == GPIOA)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  else if (port == GPIOB)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
  else if (port == GPIOC)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
  else if (port == GPIOD)
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

  for (uint8_t pin = 0; pin < 16; pin++)
  {
    if ((pins & (1 << pin)))
    {
      port->MODER &= ~(mode << pin * 2);
      port->MODER |= (mode << pin * 2);
      if (mode == MODE_OUT || mode == MODE_AF)
      {
        if (mode == MODE_AF)
        {
          port->AFR[pin >> 3] |= (af << (pin & 0x07) * 4);
        }
        // set GPIO PORT Mode Register
        port->OTYPER |= (oTyper << pin); // set GPIO PORT OUTPUT Type Register
        port->OSPEEDR |= (speed << pin * 2);
      }
      port->PUPDR |= (pushpull << pin * 2); // set GPIO PORT Push-Pull Register
    }
  }
}
/*
 * 1:GPIO PORTX
 * 2:GPIO ORE PINS PXX | PXX
 * 3:GPIO AF AF_XXX
 *
 */
void GPIO_AFConfig(GPIO_TypeDef * port, uint16_t pins, uint8_t altF)
{
  uint8_t pin = 0x00;
  while (pins >> pin)
  {
    if ((pins & (1 << pin)))
    {
      port->AFR[pin >> 3] |= (altF << (pin & 0x07) * 4);
    }
    pin++;
  }

}

void IT_Init(IRQn_Type irq, uint16_t priority, uint16_t subPriority, FunctionalState state)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  NVIC_InitStructure.NVIC_IRQChannel = irq;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = priority;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = subPriority;
  NVIC_InitStructure.NVIC_IRQChannelCmd = state;
  NVIC_Init(&NVIC_InitStructure);
  NVIC_EnableIRQ(irq);
}

