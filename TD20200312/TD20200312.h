/**
 * \file TD20200312.h
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief header to TD20200312
 */

#pragma once
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// preprocessor symbols
#define N 30

// preprocessor macros

// enumerated types
typedef enum
{
    E_NO_ERROR = 0,
    E_FILE_OPEN,
    E_FILE_CLOSE,
    E_FILE_WRITE,
    E_FILE_READ,
    E_MALLOC
} eErrorCode;

// structured types
#pragma pack(1)
typedef struct
{
    uint32_t numData;
    double *t;
} sData;
#pragma pack()
// unions types

// functions prototypes

// externals
