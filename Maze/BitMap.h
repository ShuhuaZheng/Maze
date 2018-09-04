#ifndef BITMAP_H
#define BITMAP_H

#include <windows.h>


struct color_vector
{
   BYTE r;
   BYTE g;
   BYTE b;
};

class cBitmap
{
public:
// constructor
cBitmap(char * filename,
BYTE red_color_key,
BYTE green_color_key,
BYTE blue_color_key);

// arrays are dynamic, so we can't have any leaks
~cBitmap();

// returns the width of the bitmap in pixels
LONG GetWidth();

// returns the height of the bitmap in pixels
LONG GetHeight();

// returns a long int with rgba data for point (x, y)
COLORREF GetPixel(int x, int y);

// paints a pixel in the bitmap
void PutPixel(int x, int y,
BYTE red, BYTE green, BYTE blue, BYTE alpha);

// saves a bitmap to the given file
void SaveBitmap(char * filename);

private:
// bitmap file header, standard Winblows format
BITMAPFILEHEADER m_header;

// bitmap information, like height, width, and pixel format
BITMAPINFOHEADER m_info;

// pixel data
BYTE * m_pixel_data;
BYTE * m_rgba_data;

// used for transparency (m_rgba_data is OpenGL ready)
color_vector m_colorkey;
};

#endif