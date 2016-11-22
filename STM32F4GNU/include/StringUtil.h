/*
 * StringUtil.h
 *
 *  Created on: Jun 22, 2016
 *      Author: RoyerAriel
 */

#ifndef STRINGUTIL_H_
#define STRINGUTIL_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "cmsis_device.h"
#include "define.h"

void ConverToStr(int32_t var, char *, uint8_t);
void floatToStr( double, char *str);

#ifdef __cplusplus
}
#endif
#endif /* STRINGUTIL_H_ */
