/**
  \file      wav.h
  \brief     header file for wav.c
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-10 14:10:32
**/

#pragma once
#include <stdint.h>
#include <stdio.h>

// preprocessor symbols

// preprocessor macros

// enumerated types

// structured types
#pragma pack(1)
typedef struct
{
    uint8_t riff[4]; // must contain "RIFF"
    uint32_t length; // must contain total length of file - 8
    uint8_t wav[4];  // must contain "WAVE"
} sRiffHeader;

typedef struct
{
    uint8_t fmt[4];            // must contain "fmt "
    uint32_t length;           // must contain 0x10
    uint16_t audio_format;     // must contain 1 for PCM
    uint16_t channel_number;   // 1 = mono, 2 = stereo, ...
    uint32_t sample_rate;      // in Hz
    uint32_t byte_rate;        // == sample_rate * channel_number * BitsPerSample/8
    uint16_t bytes_per_sample; // 1=8 bit Mono, 2=8 bit Stereo or 16 bit Mono, 4=16 bit Stereo
    uint16_t bits_per_sample;  // = 8, 16
} sFormatHeader;

typedef struct
{
    uint8_t data[4]; // must contain data
    uint32_t length; // length of data;
} sDataHeader;

typedef struct
{
    sRiffHeader riff;
    sFormatHeader format;
    sDataHeader data;
} sWavHeader;
#pragma pack()

// unions types

// functions prototypes

// externals

// end of wav.h