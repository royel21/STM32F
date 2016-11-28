/*
 * Util.cpp
 *
 *  Created on: Nov 8, 2016
 *      Author: RoyerAriel
 */
#include "Util.h"
#include "misc.h"
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
          uint32_t temp_port = port->AFR[pin >> 3];
          temp_port |= (af << (pin & 0x07) * 4);
          port->AFR[pin >> 3] = temp_port;
        }
        // set GPIO PORT Mode Register
        port->OTYPER |= (oTyper << pin); // set GPIO PORT OUTPUT Type Register
        port->OSPEEDR |= (speed << pin * 2);
      }
      port->PUPDR |= (pushpull << pin * 2); // set GPIO PORT Push-Pull Register
    }
  }
}

///* Enable the selected interrupt
///* 1:IRQn_Type
///* 2:Priority
///* 3:SubPriority
void InterruptEnabler(IRQn_Type irq, uint16_t priority, uint16_t subPriority)
{
  uint8_t tmppriority = 0x00, tmppre = 0x00, tmpsub = 0x0F;

  /* Compute the Corresponding IRQ Priority --------------------------------*/
  tmppriority = (0x700 - ((SCB->AIRCR) & (uint32_t) 0x700)) >> 0x08;
  tmppre = (0x4 - tmppriority);
  tmpsub = tmpsub >> tmppriority;

  tmppriority = priority << tmppre;
  tmppriority |= (uint8_t) (subPriority & tmpsub);

  tmppriority = tmppriority << 0x04;

  NVIC->IP[irq] = tmppriority;

  /* Enable the Selected IRQ Channels --------------------------------------*/
  NVIC->ISER[irq >> 0x05] = (uint32_t) 0x01 << (irq & (uint8_t) 0x1F);
}

