/*
 * printer.h
 *
 *  Created on: Jun 30, 2016
 *      Author: RoyerAriel
 */

#ifndef PRINTER_H_
#define PRINTER_H_

#include "StringUtil.h"
#include "define.h"



class Printer {

	public:
    virtual void WriteByte(const char);
		void print(char);
		void print(int, uint8_t = DEC);
		void print(int32_t, uint8_t = DEC);
		void print(uint32_t, uint8_t = DEC);
		void print(double);

		void print(const char *);
		void print(const char *, char);
		void print(const char *, int, uint8_t = DEC);
		void print(const char *, int32_t, uint8_t = DEC);
		void print(const char *, uint32_t, uint8_t = DEC);
		void print(const char *, double);
};

#endif /* PRINTER_H_ */
