#ifndef UTIL_H_
#define UTIL_H_

#include "cmsis_device.h"
#include "define.h"

#ifdef __cplusplus
extern "C" {
#endif

void InterruptEnabler(IRQn_Type, uint16_t, uint16_t);

void GPIO_Config(GPIO_TypeDef *port, uint16_t pints, uint8_t mode, uint8_t pushpull = 0,
    uint8_t otyper = 0, uint8_t speed = 0, uint8_t af = 0);

#ifdef __cplusplus
}
#endif

#endif
