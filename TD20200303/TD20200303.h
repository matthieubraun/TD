/**
 * \file TD20200227.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200227
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// preprocessor symbols
#define PI 3.141592654
#define DELTA_ANGLE (PI / 200.)

// preprocessor macros

// enumerated types
typedef enum
{
    E_NO_ERROR = 0,
    E_FILE_OPEN,
    E_FILE_CLOSE,
    E_FILE_WRITE,
    E_FILE_READ
} eErrorCode;

// structured types

// unions types

// functions prototypes

// externals
