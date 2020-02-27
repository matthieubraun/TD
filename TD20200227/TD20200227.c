/**
 * \file TD20200227.c
 * \version 1.0
 * \date 27/02/2020 - 15:33:28
 * \brief text file basics 2
 */

#include "TD20200227.h"

int main(int argc, char *argv[])
{
    eErrorCode errorCode = E_NO_ERROR;

    const char *fileName = "data.txt";
    FILE *f = NULL;
    long size = 0;
    char s[LINE_MAX_LENGTH];
    double x = 0.;
    int ret = 0;

    f = fopen(fileName, "r");
    if (f == NULL)
    {
        errorCode = E_FILE_OPEN;
        printf("Error while opening the file %s for reading.\n", fileName);
    }

    if (errorCode == E_NO_ERROR)
    {

        printf("File %s opened successfuly.\n", fileName);

        fseek(f, 0, SEEK_END);
        size = ftell(f);
        printf("File size=%ld\n", size);
        rewind(f); // set read position to beginning of file
    }

    if (errorCode == E_NO_ERROR)
    {

        do
        {
            fgets(s, LINE_MAX_LENGTH, f);
            if (!feof(f))
            {
                printf("s=[%s]  %d bytes\n", s, strlen(s));
            }
        } while (!feof(f));
    }

    if (errorCode == E_NO_ERROR)
    {
        rewind(f); // set read position to beginning of file
        do
        {
            // read with fscanf
            ret = fscanf(f, "%lf", &x);
            if (ret != 1)
            {
                errorCode = E_FILE_READ;
            }
            if (!errorCode && !feof(f))
            {
                printf("%lf\n", x);
            }
        } while (!feof(f));
    }

    if (errorCode == E_NO_ERROR)
    {
        if (0 != fclose(f))
        {
            errorCode = E_FILE_CLOSE;
            printf("Error while closing the file %s.\n", fileName);
        }
    }

    return errorCode;
}
