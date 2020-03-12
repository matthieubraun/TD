/**
  \file      TD20200312.c
  \brief     bin file / dynamic alloc
  \author    Pierre BRESSY
  \version   1.0
  \date      2020-03-03 13:41:24
  \details
    
**/

#include "TD20200312.h"

int readFile()
{
    eErrorCode returnCode = E_NO_ERROR;
    const char *filename = "data.bin";
    FILE *f = NULL;
    int ret = 0;
    sData data;
    double sum = 0.;
    double mean = 0.;

    uint32_t k = 0;

    f = fopen(filename, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Error, unable to read the file [%s].\n", filename);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fread(&data.numData, sizeof(uint32_t), 1, f);
        if (ret != 1)
        {
            fprintf(stderr, "Error, unable to read the file [%s].\n", filename);
            returnCode = E_FILE_READ;
        }
        data.t = malloc(data.numData * sizeof(double));
        if (data.t == NULL)
        {
            fprintf(stderr, "Error, unable to allocate memory.\n");
            returnCode = E_MALLOC;
        }
        ret = fread(data.t, sizeof(double), data.numData, f);
        if (ret != N)
        {
            fprintf(stderr, "Error, unable to read the file [%s].\n", filename);
            returnCode = E_FILE_READ;
        }
    }
    if (!returnCode)
    {
        if (data.numData)
        {
            sum = 0.;
            for (k = 0; k < data.numData; k++)
            {
                sum += data.t[k];
                //printf("%lf\n", data.t[k]);
            }
            mean = sum / data.numData;
            printf("mean=%lf\n", mean);
        }
        else
        {
            puts("No data in file.");
        }

        if (0 != fclose(f))
        {
            fprintf(stderr, "Error, unable to close the file [%s].\n", filename);
            returnCode = E_FILE_CLOSE;
        }
    }
    if (data.t)
    {
        free(data.t);
        data.t = NULL;
    }

    return returnCode;
}

int writeFile()
{
    eErrorCode returnCode = E_NO_ERROR;
    const char *filename = "data.bin";
    FILE *f = NULL;
    int ret = 0;
    uint32_t numData = N;
    double t[N];

    uint32_t k = 0;

    for (k = 0; k < N; k++)
    {
        t[k] = rand() / (double)RAND_MAX;
    }
    for (k = 0; k < N; k++)
    {
       // printf("%lf\n", t[k]);
    }

    f = fopen(filename, "wb");
    if (f == NULL)
    {
        fprintf(stderr, "Error, unable to create the file [%s].\n", filename);
        returnCode = E_FILE_OPEN;
    }
    if (!returnCode)
    {
        ret = fwrite(&numData, sizeof(uint32_t), 1, f);
        if (ret != 1)
        {
            fprintf(stderr, "Error, unable to write the file [%s].\n", filename);
            returnCode = E_FILE_WRITE;
        }
        ret = fwrite(t, sizeof(double), N, f);
        if (ret != N)
        {
            fprintf(stderr, "Error, unable to write the file [%s].\n", filename);
            returnCode = E_FILE_WRITE;
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

int main(int argc, char *argv[])
{
    eErrorCode returnCode = E_NO_ERROR;

    returnCode = writeFile();
    puts("");
    returnCode = readFile();
    return returnCode;
}