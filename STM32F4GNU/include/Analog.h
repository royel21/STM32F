/*
 * Analog.h
 *
 *  Created on: Nov 11, 2016
 *      Author: RoyerAriel
 */

#ifndef ANALOG_H_
#define ANALOG_H_




#include "cmsis_device.h"
#include "define.h"

#ifdef __cplusplus
extern "C" {
#endif

/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_PL_VH                       ((uint32_t)0x00030000)
#define DMA_SxCR_PL_M                        ((uint32_t)0x00010000)
#define DMA_SxCR_PL_H                        ((uint32_t)0x00020000)
#define DMA_SxCR_MSIZE_8bit                  ((uint32_t)0x00000000)
#define DMA_SxCR_MSIZE_16bit                 ((uint32_t)0x00002000)
#define DMA_SxCR_MSIZE_32bit                 ((uint32_t)0x00004000)
#define DMA_SxCR_PSIZE_8bit                  ((uint32_t)0x00000000)
#define DMA_SxCR_PSIZE_16bit                 ((uint32_t)0x00000800)
#define DMA_SxCR_PSIZE_32bit                 ((uint32_t)0x00001000)
#define DMA_SxCR_DIR_P2M                     ((uint32_t)0x00000000)
#define DMA_SxCR_DIR_M2P                     ((uint32_t)0x00000040)
#define DMA_SxCR_DIR_M2M                     ((uint32_t)0x00000080)
#define CH00                                 ((uint8_t)0x00)
#define CH01                                 ((uint8_t)0x01)
#define CH02                                 ((uint8_t)0x02)
#define CH03                                 ((uint8_t)0x03)
#define CH04                                 ((uint8_t)0x04)
#define CH05                                 ((uint8_t)0x05)
#define CH06                                 ((uint8_t)0x06)
#define CH07                                 ((uint8_t)0x07)
#define CH08                                 ((uint8_t)0x08)
#define CH09                                 ((uint8_t)0x09)
#define CH10                                 ((uint8_t)0x0A)
#define CH11                                 ((uint8_t)0x0B)
#define CH12                                 ((uint8_t)0x0C)
#define CH13                                 ((uint8_t)0x0D)
#define CH14                                 ((uint8_t)0x0E)
#define CH15                                 ((uint8_t)0x0F)
//	uint16_t adcVal = 0;
void analogReadWithDMAMulti(uint16_t pins, volatile uint16_t *vars, uint8_t size);
uint16_t analogRead(uint16_t);

#ifdef __cplusplus
}
#endif

#endif /* ANALOG_H_ */
