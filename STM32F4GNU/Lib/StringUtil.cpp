/*
 * StringUtil.cpp
 *
 *  Created on: Jun 22, 2016
 *      Author: RoyerAriel
 */

#include "StringUtil.h"

static uint8_t decToStr(int32_t val, char buff[], uint8_t i)
{
  do
  {
    buff[i++] = (char) (val % 10) + '0'; //integer to ANSI
    val /= 10;
  } while (val);
  return i;
}

void ConverToStr(int32_t val, char *str, uint8_t base)
{
  char numb[12];
  uint8_t i = 0, temp;

  if (base == 10)
  {
    if (val < 0)
    {
      *str++ = '-';
      val *= -1;
    }
    i = decToStr(val, numb, 0);
  }

  if (base == 16)
  {
    while (val != 0)
    {
      temp = val % 16;
      if (temp < 10)
        temp = temp + 48;
      else
        temp = temp + 55;
      numb[i++] = temp;
      val = val / 16;
    }
  }

  if (base == 2)
  {
    s32 x;
    if (val <= 0xff)
    {
      x = 0x80;
    } else
    {
      x = 0x8000;
    }
    for (; x > 0; x >>= 1)
    {
      *str++ = (val & x) ? '1' : '0';
    }
    *str = '\0';
    return;
  }

  while (i--)
  {
    *str++ = numb[i];
  }
  *str = '\0';
}

void floatToStr(double floating, char *str)
{
  char numb[16];
  uint8_t i = 0;
  floating += 0.0005;
  if (floating < 0)
  {
    *str++ = '-';
    floating *= -1;
  }

  int integer = (int) floating;
  int dec = (int) ((floating - integer) * 1000);

  if (dec > 0)
  {
    i = decToStr(dec, numb, i);

    if (dec < 100)
      numb[i++] = '0';
    if (dec < 10)
      numb[i++] = '0';
    numb[i++] = '.';
  } else
  {
    numb[i++] = '0';
    numb[i++] = '.';
  }
  i = decToStr(integer, numb, i);

  while (i--)
  {
    *str++ = numb[i];
  }
  *str = '\0';
}
