
/*
 Copyright (C) 2011 J. Coliz <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
  
 03/17/2013 : Charles-Henri Hallard (http://hallard.me)
              Modified to use the great bcm2835 library for I/O and SPI

 */

#ifndef __RF24_CONFIG_H__
#define __RF24_CONFIG_H__

#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>
#include <stddef.h>
#include "bcm2835.h"

// GCC a Arduino Missing
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define _BV(x) (1<<(x))
#define pgm_read_word(p) (*(p))
#define pgm_read_byte(p) (*(p))

// For debugging library
#undef SERIAL_DEBUG
#ifdef SERIAL_DEBUG
  #define IF_SERIAL_DEBUG(x) ({x;})
#else
  #define IF_SERIAL_DEBUG(x)
#endif


#endif // __RF24_CONFIG_H__
// vim:ai:cin:sts=2 sw=2 ft=cpp
