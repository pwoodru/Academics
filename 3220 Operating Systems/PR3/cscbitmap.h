// Code by Bidur Bohara (LSU) in collaboration with Brygg Ullmer

//Name:         Patrick Woodrum
//Instructor:   Brygg Ullmer
//Class:        3220
//Date:         11/10/2020
//File:         cscbitmap.h (header)

#ifndef BITMAP_H
#define BITMAP_H

class Bitmap
{
public:
    Bitmap();

    unsigned int bmpWidth;
    unsigned int bmpHeight;
    unsigned int bmpSize;

    unsigned char* readGrayBitmap(const char*file);
    void writeGrayBmp(unsigned char* data);

    //Added a region struct to help pass info through func's
    struct Region {
        const unsigned int w;
        const unsigned int h;
    };

private:
    unsigned char* bmpHeader;
    unsigned int offset;
    unsigned int bitsPerPixel;

};



#endif // BITMAP_H
