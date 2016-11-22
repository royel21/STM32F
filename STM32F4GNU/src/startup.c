/*
 * startup.h
 *
 *  Created on: Nov 15, 2016
 *      Author: RoyerAriel
 */

#ifndef STARTUP_C_
#define STARTUP_C_
#include "Timer.h"

void startup()
{
  //Start Systick Timer at 1ms
  Systick_Startup();

}

#endif /* STARTUP_C_ */
