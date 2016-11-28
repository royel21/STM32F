/*
 * SerialHardware.h
 *
 *  Created on: Jun 8, 2016
 *      Author: RoyerAriel
 */

#ifndef SERIALHARDWARE_HPP_
#define SERIALHARDWARE_HPP_

#include "cmsis_device.h"
#include "define.h"
#include "Printer.h"
#include "Util.h"

#define BUFFSIZE 128

class SerialHardware: public Printer
{
  private:
    USART_TypeDef *USARTx;
    uint32_t usartClock;
    char buff[BUFFSIZE];
    volatile uint8_t head;
    volatile uint8_t tail;
    char endCode;
    uint8_t ITenable;
  public:
    SerialHardware(USART_TypeDef *, uint16_t, uint8_t);

    void WriteByte(const char);
    void Init(uint32_t);
    void receiveByteIT();
    void setEndCode(char);

    void println(char);
    void println(int, uint8_t base = DEC);
    void println(int32_t var, uint8_t base = DEC);
    void println(uint32_t var, uint8_t base = DEC);
    void println(double var);

    void println(const char *);
    void println(const char *, int, uint8_t base = DEC);
    void println(const char *, int32_t, uint8_t base = DEC);
    void println(const char *, uint32_t, uint8_t base = DEC);
    void println(const char *, double);

    inline void println()
    {
      WriteByte('\n');
      WriteByte('\r');
    }

    char readByte();
    uint8_t hasData()
    {
      return (uint8_t) (BUFFSIZE + head - tail) % BUFFSIZE;
    }

};

#ifdef USE_USART1
extern SerialHardware Serial1;
#endif

#ifdef USE_USART2
extern SerialHardware Serial2;
#endif

#ifdef USE_USART3
extern SerialHardware Serial3;
#endif

#ifdef USE_USART6
extern SerialHardware Serial6;
#endif

#endif /* SERIALHARDWARE_HPP_ */
