/**
 * \file TD20200225.c
 * \version 1.0
 * \date 25/02/2020 - 15:33:28
 * \brief text file basics
 */

#include "TD20200225.h"


int main(int argc, char* argv[])
{
    const double xMin=1.0;
    const double xMax=10.0;
    const double xStep=0.1;

    const char* fileName="data.txt";
    FILE* f=NULL;

    double x=0.;
    int returnCode = 0;

    f=fopen(fileName,"w");
    if(f==NULL) {
        printf("Error while creating the file %s.\n",fileName);
        returnCode=1;
    }
    else {
        printf("File %s created successfuly.\n",fileName);

        for(x=xMin;x<=xMax;x+=xStep) {
            fprintf(f,"%7.4lf\n",x);
        }

        if(0!=fclose(f)) {
            printf("Error while closing the file %s.\n",fileName);
        }
    }
    return returnCode;
}

