    /**
  \file      TD20200310-2.c
  \brief     text file
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200310-2.h"

int main(int argc, char *argv[])
{
  eErrorCode returnCode = E_NO_ERROR;

  sData1 d1={0};
  uint32_t k = 0;
  uint8_t *p = NULL;

  d1.a = 0x55;
  d1.b = 0x11223344;
  d1.c = 0xAA;

  printf("Size of sData1: %lu bytes.\n", sizeof(sData1));
  p = &d1;
  for (k = 0; k < sizeof(sData1); k++)
  {
    printf("%02X ", *(p++));
  }
  puts("");
 
  return returnCode;
}