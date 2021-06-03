/*******************
Patrick Woodrum
CpSc 1020 Sm19
pwoodru@clemson.edu
********************/

#ifndef ENCODE
#define ENCODE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Structs
typedef struct header {
  char magicNum[3];
  int width, height, maxVal;
} header_t;

typedef struct pixel {
  unsigned int r, g, b;
} pixel_t;

void readHeader(FILE* input, header_t* header);

pixel_t** allocateMemory(header_t header);

pixel_t** readPixel(FILE* input, header_t header);

void writeHeader(FILE* out, header_t header);

void writePixels(FILE* out, pixel_t** pixels, header_t header);

void removeDigit(pixel_t** pixels, header_t header);

void encodeMsg(FILE* out, header_t header, pixel_t** pixels, char* message);

void dec2bin(int arr[9], int b);

#endif
