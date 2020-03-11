/**
 * \file TD20200310-2.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200310-2
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// preprocessor symbols
#define N 1024

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
#pragma pack(1)
typedef struct
{
    uint8_t a;
    uint32_t b;
    uint8_t c;
} sData1;
#pragma pack()

// unions types

// functions prototypes

// externals
