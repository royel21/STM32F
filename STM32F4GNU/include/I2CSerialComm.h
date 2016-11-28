/*
 * I2CSerialConm.h
 *
 *  Created on: Jun 18, 2016
 *      Author: Royel
 */

#ifndef I2CSERIALCOMM_H_
#define I2CSERIALCOMM_H_

#include "cmsis_device.h"
#include "I2Cdefine.h"
#include "define.h"
#include "Util.h"

class I2CSerialComm
{
  private:
    uint8_t address;
    I2C_TypeDef *I2Cx;
  public:
		I2CSerialComm(I2C_TypeDef *i2c, uint16_t pins);

    void setAddress(uint8_t);
    uint8_t Start(uint8_t, uint8_t);

    uint8_t Write(uint8_t);
    void WriteTo(uint8_t, uint8_t);
    void WriteToReg(uint8_t, uint8_t, uint8_t);
    void WriteMultiReg(uint8_t, uint8_t *, uint8_t);
    void WriteMulti(uint8_t, uint8_t *, uint8_t);

    uint8_t ReadData(uint8_t);
    uint8_t ReadFrom(uint8_t, uint8_t);
    void ReadMultiReg(uint8_t, uint8_t, uint8_t *, uint8_t size);

    void Stop();
    void hardReset(void);
};

extern I2CSerialComm I2C1Comm;

#endif /* I2CSERIALCOMM_H_ */
