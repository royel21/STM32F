/*
 * I2Cdefine.h
 *
 *  Created on: Jun 16, 2016
 *      Author: RoyerAriel
 */

#ifndef I2CDEFINE_H_
#define I2CDEFINE_H_

#include "define.h"


/*****I2C Macros*****/
#define  I2C_ACK				((uint8_t)0)					/** I2C Write bit **/
#define  I2C_NACK 			 	((uint8_t)1)
#define  I2C_SPD				((uint32_t)400000)				//I2C Speed 400khz
#define  I2C_WR				 	((uint8_t)0)					/** I2C Write bit **/
#define  I2C_RD 			 	((uint8_t)1)					/** I2C Read bit **/
#define  I2C_EVNT_MS  			((uint32_t)0x00030001)	/* BUSY, MSL and SB flag */
#define  I2C_EVNT_M_Tx        	((uint32_t)0x00070082)  /* BUSY, MSL, ADDR, TXE and TRA flags */
#define  I2C_EVNT_M_Rx          ((uint32_t)0x00030002)  /* BUSY, MSL and ADDR flags */
/* Master RECEIVER mode -----------------------------*/
/* --EV7 */
#define  I2C_EVENT_MBRXD          ((uint32_t)0x00030040)  /* BUSY, MSL and RXNE flags */
/* Master TRANSMITTER mode --------------------------*/
/* --EV8 */
#define  I2C_EVENT_MBTXG        ((uint32_t)0x00070080) /* TRA, BUSY, MSL, TXE flags */
/* --EV8_2 */
#define  I2C_EVENT_MBTXD        ((uint32_t)0x00070084)  /* TRA, BUSY, MSL, TXE and BTF flags */

#define WHO_AM_I  				((uint8_t)0x75)

#endif /* I2CDEFINE_H_ */
