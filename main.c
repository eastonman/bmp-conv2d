#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"
#include "cv.h"

int main(int argc, char *argv[])
{
    BMPImage *img = LoadBMPImage("girl.bmp");
    BMPImage *ResultImg;

    float const kernel[3][3] = {{-1. / 8, -1. / 8, -1. / 8},
                                {-1. / 8, 1, -1. / 8},
                                {-1. / 8, -1. / 8, -1. / 8}};
    /*float const kernel[3][3] = {{-1. / 2, 0, 0},
                                {0, 0, 0},
                                {0, 0, 1. / 2}};*/
    /*float const kernel[3][3] = {{0.089, 0.112, 0.089},
                                {0.112, 0.100, 0.112},
                                {0.089, 0.112, 0.089}};*/

    ResultImg = Conv2D(img, kernel);

    // Save Result
    if (SaveBMPImage("gaussian.bmp", ResultImg))
    {
        printf("BMP image successfully processed.\n");
    }
    else
    {
        printf("Error proccessing bmp image.\n");
    }

    free(img);
    free(ResultImg);

    return 0;
}
