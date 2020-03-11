/**
  \file      TD20200310-1.c
  \brief     text file
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200310-1.h"

int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;
    uint32_t count = 0;
    char s[N] = {0};

    do
    {
        fgets(s, N, stdin);
        count++;
    } while (!feof(stdin));

    fprintf(stdout, "%u line%s.\n", count, count > 1 ? "s" : "");

    return returnCode;
}