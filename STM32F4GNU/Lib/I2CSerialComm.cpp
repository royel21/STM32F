/*
 * I2CSerialComm.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: Royel
 */

#include "I2CSerialComm.h"

I2CSerialComm::I2CSerialComm(GPIO_TypeDef *port, I2C_TypeDef *I2Cx, uint16_t pins, uint8_t af)
{
	this->I2Cx = I2Cx;
	address = 0;
	// init GPIOB
  GPIO_Config(port, pins, MODE_AF, PULL_UP, OTYPER_OD, SPEED_100MHz, af);

  if (I2Cx == I2C1)
  {
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
  } else if (I2Cx == I2C2)
  {
    RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
  }
	// configure I2Cx

	I2C_InitTypeDef I2C_InitStruct;
	I2C_InitStruct.I2C_ClockSpeed = I2C_SPD; 		// 100kHz
	I2C_InitStruct.I2C_Mode = I2C_Mode_I2C;			// I2C mode
	I2C_InitStruct.I2C_DutyCycle = I2C_DutyCycle_2;	// 50% duty cycle --> standard
	I2C_InitStruct.I2C_OwnAddress1 = 0x00;// own address, not relevant in master mode
	I2C_InitStruct.I2C_Ack = I2C_Ack_Enable;// disable acknowledge when reading (can be changed later on)
	I2C_InitStruct.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit; // set address length to 7 bit addresses
	I2C_Init(I2Cx, &I2C_InitStruct);				// init I2Cx
	I2Cx->CR1 |= I2C_CR1_PE;
}

/*Set the address of the device to work with*/
void I2CSerialComm::setAddress(uint8_t address)
{
	this->address = (address << 1);
}

/* Send the address to the i2c line to ready the Slave */
uint8_t I2CSerialComm::Start(uint8_t addr, uint8_t direction)
{
	uint16_t timeout = 300;
	while ((I2Cx->SR2 & I2C_SR2_BUSY) && timeout--)
		;

	I2Cx->CR1 |= I2C_CR1_START;
	/* Test on EV5 and clear it */
	timeout = 250;
	while (!I2C_CheckEvent(I2Cx, I2C_EVNT_MS) && timeout)
		timeout--;

	/* Send Slave address for write */
	I2Cx->DR = (addr | direction);

	return 0;
}

/** Write one byte to the slave device
 * and after that a STOP condition is transmitted
 */
uint8_t I2CSerialComm::Write(uint8_t data)
{
	int timeout = 500;
	while (!I2C_CheckEvent(I2Cx, I2C_EVNT_M_Tx) && timeout)
		timeout--;
	/* Write Data to Slave*/
	I2Cx->DR = data;
	/* Test on EV8 and clear it */
	return 0;
}
void I2CSerialComm::WriteTo(uint8_t addr, uint8_t data)
{
	Start(addr << 1, I2C_WR);
	Write(data);
	Stop();
}
/** Write one data to a  register */
void I2CSerialComm::WriteToReg(uint8_t addr, uint8_t reg, uint8_t data)
{
	I2C1Comm.Start(addr, I2C_WR);
	I2C1Comm.Write(reg);
	I2C1Comm.Write(data);
	I2C1Comm.Stop();
}
/** Write to one register */
void I2CSerialComm::WriteMultiReg(uint8_t reg, uint8_t *data, uint8_t size)
{
	Start(address, I2C_WR);
	Write(reg);

	while (size)
	{
		Write(*data);
		data++;
		size--;
	}

	Stop();
}
/** Read data from register*/
uint8_t I2CSerialComm::ReadFrom(uint8_t addr,uint8_t reg)
{
	uint8_t data;

	Start(addr, I2C_WR);

	Write(reg);

	I2Cx->CR1 |= I2C_CR1_STOP;

	while (I2Cx->SR2 != 0)
		;

	Start(addr, I2C_RD);

	while (!(I2Cx->SR1 & I2C_SR1_ADDR))
		;

	I2Cx->CR1 &= ~I2C_CR1_ACK;
	I2Cx->SR2;

	while (!(I2Cx->SR1 & I2C_SR1_RXNE))
		;

	data = I2Cx->DR & 0xFF;

	Stop();
	I2Cx->CR1 |= I2C_CR1_ACK;
	return data;
}

void I2CSerialComm::ReadMultiReg(uint8_t addr, uint8_t reg, uint8_t *data,
		uint8_t size)
{
	Start(addr, I2C_WR);

	Write(reg);

	I2Cx->CR1 |= I2C_CR1_STOP;

	while (I2Cx->SR2 != 0)
		;

	Start(addr, I2C_RD);
	while (!(I2Cx->SR1 & I2C_SR1_ADDR))
		;
	I2Cx->SR2;

	while (size)
	{

		if (size == 1)
		{
			I2Cx->CR1 &= ~I2C_CR1_ACK;
			I2Cx->SR2;
		}

		if (I2Cx->SR1 & I2C_SR1_RXNE)
		{
			*data++ = I2Cx->DR;
			size--;
		}
	}

	I2Cx->CR1 |= I2C_CR1_STOP;

	while (I2Cx->SR2 != 0)
		;
	I2Cx->CR1 |= I2C_CR1_ACK;
}
/* Reads one byte from the slave device
 * and doesn't acknowledge the received data
 * after that a STOP condition is transmitted
 */

uint8_t I2CSerialComm::ReadData(uint8_t nack)
{
	/* Waiting for ADDR condition */
	uint8_t data;
	uint8_t timeout = 255;
	if (!nack)
	{
		return (I2Cx->DR & 0xFF);
	} else
	{
		/* DISABLE ACKNOWLEDGE */
		I2Cx->CR1 &= ~I2C_CR1_ACK;

		while (!(I2Cx->SR1 & I2C_SR1_RXNE) && timeout)
			timeout--;
		I2Cx->SR2;
		Stop();

		data = I2Cx->DR & 0xFF;

		/* ENABLE ACKNOWLEDGE */
		I2Cx->CR1 |= I2C_CR1_ACK;
		return data;
	}
}

/*Trasnmitt a stop condition to the Slave */
void I2CSerialComm::Stop()
{
	/* Send STOP condition */
	I2Cx->CR1 |= I2C_CR1_STOP;
	while (I2Cx->SR1 == I2C_SR2_BUSY)
		;
}

void I2CSerialComm::hardReset()
{
	/* Send STOP condition */
	Stop();
	I2Cx->CR1 |= I2C_CR1_SWRST;
	I2Cx->CR1 &= ~I2C_CR1_SWRST;
	I2Cx->CR1 |= I2C_CR1_PE;
}
//void I2C1_EV_IRQHandler(void)
//{
//
//    switch(I2C_GetLastEvent(I2C2))
//    {
//    case I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED :
//        break;
//    case I2C_EVENT_SLAVE_BYTE_RECEIVED:
//       // i2c_read_packet[Rx_Index] = I2C_ReceiveData(I2C2); // Store the packet in i2c_read_packet.
//        //Rx_Index++;
//        break;
//    case I2C_EVENT_SLAVE_STOP_DETECTED :
//       // Rx_Index = 0;
//       // packets_recv_i2c++;
//       // i2cProcessPacket();
//        break;
//    case I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED:
//       // I2C_SendData(I2C2, i2c_packet_to_send[0]);
//       // Tx_Index++;
//        break;
//    case I2C_EVENT_SLAVE_BYTE_TRANSMITTED:
//        //I2C_SendData(I2C2, i2c_packet_to_send[Tx_Index]);
//        //Tx_Index++;
//        break;
//    case I2C_EVENT_SLAVE_ACK_FAILURE:
//       // Tx_Index = 0;
//      //  packets_sent_i2c++;
//        break;
//    default:
//        break;
//    }
//}
I2CSerialComm I2C1Comm = I2CSerialComm(GPIOB, I2C1, P08 | P09, GPIO_AF9_I2C2);
