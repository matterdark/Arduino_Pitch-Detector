/**
 * @brief Assert handler / memory tools / ..
 * @file debug.h
 *
 * Platform: Arduino UNO R3 using Arduino IDE
 *
 * GNU GENERAL PUBLIC LICENSE Version 3, check the file LICENSE for more information
 * (c) Copyright 2015, Coert Vonk
 * All rights reserved.  Use of copyright notice does not imply publication.
 * All text above must be included in any redistribution
 **/

#pragma once
#include <Arduino.h>
#include <stdint.h>

// other option is to use __BASE_FILE__
#define ASSERT(x) do { if (!(x)) { Debug::assertPrint(__func__, __LINE__); /*blink LED*/} } while (0)

namespace Debug {

    void
        assertPrint( char const * const func,
                     int const lineno );

    unsigned int const
        getMemFree( void );

    void
        getMemInUse( unsigned int const   ramend,
                     unsigned int const   sp,
                     unsigned int * const dataSize,
                     unsigned int * const bssSize,
                     unsigned int * const heapSize,
                     unsigned int * const stackSize );

    void
        showMemUsage( void );

    void
        hexDump( uint8_t const * p,    // pointer to 1st byte to display as hexadecimal
                 uint16_t * const pos, // number of bytes already displayed
                 uint16_t const n );   // number of bytes to display

};
