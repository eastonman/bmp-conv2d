#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "cv.h"

const char toRGB[3] = {'R', 'G', 'B'};

BMPImage *Conv2D(BMPImage *Source, const float kernel[][KERNEL_SIZE])
{
    // Initial Result struct on heap
    BMPImage *Result;
    Result = malloc(sizeof(BMPImage));
    if (Result == NULL) // Handlers error
    {
        return NULL;
    }
    memset(Result, 0, sizeof(BMPImage));
    // Set Data size
    Result->imageData = (PixelBlock *)malloc(sizeof(PixelBlock) * Source->width * Source->height);
    memset(Result->imageData, 0, sizeof(PixelBlock) * Source->width * Source->height);
    // Copy meta data from source
    Result->width = Source->width;
    Result->height = Source->height;
    Result->channels = Source->channels;

    // Go through all pixels to get convolution
    for (int location_x = 0; location_x < Source->width; location_x++)
    {
        for (int location_y = 0; location_y < Source->height; location_y++)
        {
            // Initial a input array to extract float number
            PixelBlock input[KERNEL_SIZE][KERNEL_SIZE];
            memset(input, 0, sizeof(input));

            // Extract pixels arround current location
            int radius = (KERNEL_SIZE - 1) / 2; // Better compatibility
            for (int i = 0; i < KERNEL_SIZE; i++)
            {
                for (int j = 0; j < KERNEL_SIZE; j++)
                {

                    // GetPixel will handle special cases
                    input[i][j] = GetPixel(Source, location_x + i - radius, location_y + j - radius);
                }
            }

            Result->imageData[location_y * Source->width + location_x] = conv(input, kernel);
        }
    }
    return Result;
}

PixelBlock conv(PixelBlock input[][KERNEL_SIZE], const float kernel[][KERNEL_SIZE])
{
    PixelBlock result;
    result.R = result.G = result.B = 0;
    for (int i = 0; i < KERNEL_SIZE; i++)
    {
        for (int j = 0; j < KERNEL_SIZE; j++)
        {
            int16_t newR = input[i][j].R * kernel[i][j];
            int16_t newG = input[i][j].G * kernel[i][j];
            int16_t newB = input[i][j].B * kernel[i][j];

            // R
            result.R += newR;

            // G
            result.G += newG;

            // B
            result.B += newB;
        }
    }
    return result;
}
