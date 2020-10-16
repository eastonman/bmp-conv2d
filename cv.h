#ifndef CV_H
#define CV_H

#include "bmp.h"

#define KERNEL_SIZE 3

// Conv2D do 2D convolution on given Source and kernel
// then return a new BMPImage
BMPImage *Conv2D(BMPImage *Source, const float kernel[][KERNEL_SIZE]);

// conv do convolution on given same size input and kernel
PixelBlock conv(PixelBlock input[][KERNEL_SIZE], const float kernel[][KERNEL_SIZE]);

#endif