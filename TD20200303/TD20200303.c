/**
  \file      TD20200303.c
  \brief     text file
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200303.h"

int saveToTextFile(void)
{
    eErrorCode returnCode = E_NO_ERROR;

    const char *fileName = "data.txt";
    FILE *f = NULL;

    double angle = 0.;
    double s = 0.;

    f = fopen(fileName, "w");
    if (f == NULL)
    {
        printf("Error while creating the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }

    if (!returnCode)
    {
        angle = PI / 10.;
        s = sin(angle);
        fprintf(f, "%.5lf %.5lf\n", angle, s);
    }

    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            printf("Error while closing the file %s.\n", fileName);
            returnCode = E_FILE_CLOSE;
        }
    }
    return returnCode;
}

int readFromTextFile(void)
{
    eErrorCode returnCode = E_NO_ERROR;

    const char *fileName = "data.txt";
    FILE *f = NULL;

    double angle = 0.;
    double s = 0.;

    int ret = 0;

    f = fopen(fileName, "r");
    if (f == NULL)
    {
        printf("Error while opening the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }

    if (!returnCode)
    {
        {
            ret = fscanf(f, "%lf%lf\n", &angle, &s);
            if (ret == 2)
            {
                printf("read angle=%+10.7lf\n", angle);
                printf("read sin  =%+10.7lf\n", s);
                printf("\nComparison between values using text file...\n\n");
                printf("delta angle=%e\n", angle - PI / 10.);
                printf("delta sin  =%e\n", s - sin(PI / 10.));
            }
        }
    }

    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            printf("Error while closing the file %s.\n", fileName);
            returnCode = E_FILE_CLOSE;
        }
    }
    return returnCode;
}

int saveToBinaryFile(void)
{
    eErrorCode returnCode = E_NO_ERROR;

    const char *fileName = "data.bin";
    FILE *f = NULL;
    double angle = 0.;
    double s = 0.;

    int ret = 0;

    f = fopen(fileName, "wb");
    if (f == NULL)
    {
        printf("Error while creating the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }

    if (!returnCode)
    {
        angle = PI / 10.;
        s = sin(angle);
        ret = fwrite(&angle, sizeof(double), 1, f);
        ret += fwrite(&s, sizeof(double), 1, f);
        if (ret != 2)
        {
            returnCode = E_FILE_WRITE;
            printf("Error while writing the file %s.\n", fileName);
        }
    }

    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            printf("Error while closing the file %s.\n", fileName);
            returnCode = E_FILE_CLOSE;
        }
    }
    return returnCode;
}

int readFromBinFile(void)
{
    eErrorCode returnCode = E_NO_ERROR;

    const char *fileName = "data.bin";
    FILE *f = NULL;
    double angle = 0.;
    double s = 0.;
    int ret = 0;

    f = fopen(fileName, "rb");
    if (f == NULL)
    {
        printf("Error while opening the file %s.\n", fileName);
        returnCode = E_FILE_OPEN;
    }

    if (!returnCode)
    {
        {
            ret = fread(&angle, sizeof(double), 1, f);
            ret += fread(&s, sizeof(double), 1, f);
            if (ret == 2)
            {
                printf("read angle=%+10.7lf\n", angle);
                printf("read sin  =%+10.7lf\n", s);

                printf("\nComparison between values using binary file...\n\n");
                printf("delta angle=%e\n", angle - PI / 10.);
                printf("delta sin  =%e\n", s - sin(PI / 10.));
            }
            else
            {
                returnCode = E_FILE_READ;
                printf("Error while reading the file %s.\n", fileName);
            }
        }
    }

    if (!returnCode)
    {
        if (0 != fclose(f))
        {
            printf("Error while closing the file %s.\n", fileName);
            returnCode = E_FILE_CLOSE;
        }
    }
    return returnCode;
}

int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;

    returnCode = saveToTextFile();
    returnCode = readFromTextFile();

    returnCode = saveToBinaryFile();
    returnCode = readFromBinFile();

    return returnCode;
}