#ifndef BMP_H
#define BMP_H
#include <stdbool.h>
#include <stdint.h>
typedef struct
{
    uint32_t bfSize;     //文件大小
    uint16_t fReserved1; //保留字
    uint16_t fReserved2; //保留字
    uint32_t fOffBits;   //位图数据偏移字节数
} BitMapFileHeader;      /*文件头*/

typedef struct
{
    uint32_t biSize;         //结构体长度
    int32_t biWidth;         //位图宽度
    int32_t biHeight;        //位图高度
    uint16_t biPlanes;       //位图平面数
    uint16_t biBitCount;     //颜色位数
    uint32_t biCompression;  //压缩方式
    uint32_t biSizeImage;    //实际位图数据占用的字节数
    int32_t biXPelsPerMeter; //X方向分辨率
    int32_t biYPelsPerMeter; //Y方向分辨率
    uint32_t biClrUsed;      //使用的颜色数
    uint32_t biClrImportant; //重要颜色数
} BitMapInfoHeader;          /*位图信息头*/

typedef struct
{
    unsigned char B;
    unsigned char G;
    unsigned char R;
} PixelBlock;

typedef struct
{
    int width;
    int height;
    int channels;
    PixelBlock *imageData;
} BMPImage;

BMPImage *LoadBMPImage(char *path);
bool SaveBMPImage(char *path, BMPImage *bmpImg);

// GetPixel return 0 if input location is invalid
PixelBlock GetPixel(BMPImage *img, int location_x, int locaion_y);

#endif
