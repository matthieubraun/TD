/**
  \file      TD20200310-3.c
  \brief     text file
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200310-3.h"

int main(int argc, char *argv[])
{
  eErrorCode returnCode = E_NO_ERROR;
  const char *filename = "61s.wav";
  FILE *f = NULL;
  sWavHeader header = {0};
  int ret = 0;

  f = fopen(filename, "rb");
  if (f == NULL)
  {
    fprintf(stderr, "Error, unable to open the file [%s].\n", filename);
    returnCode = E_FILE_OPEN;
  }
  if (!returnCode)
  {
    ret = fread(&header, sizeof(sWavHeader), 1, f);
    if (ret != 1)
    {
      fprintf(stderr, "Error, unable to read the file [%s].\n", filename);
      returnCode = E_FILE_READ;
    }
    else
    {
      printf("Sampling rate: %u Hz\n", header.format.sample_rate);
    }
  }
  if (!returnCode)
  {
    if (0 != fclose(f))
    {
      fprintf(stderr, "Error, unable to close the file [%s].\n", filename);
      returnCode = E_FILE_CLOSE;
    }
  }

  return returnCode;
}