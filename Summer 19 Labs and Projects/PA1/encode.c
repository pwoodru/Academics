/*******************
Patrick Woodrum
CpSc 1020 Sm19
pwoodru@clemson.edu
********************/

#include <stdio.h>
#include <stdlib.h>
#include "encode.h"

//This function reads the header of a ppm file.
void readHeader(FILE* input, header_t* header) {
  //Reads header info from the input file
  fscanf(input, "%s ", header->magicNum);
  fscanf(input, "%d %d ", &header->width, &header->height);
  fscanf(input, "%d ", &header->maxVal);
}

//This function will be used to write the header to the output ppm file.
void writeHeader(FILE* out, header_t header) {
  //Prints header numbers to output file
  fprintf(out, "%s %d ", header.magicNum, header.width);
  fprintf(out, "%d %d\n", header.height, header.maxVal);
}

//This function should dynamically allocate the memory for the 2D array of type
//pixels_t that will hold the RGb values for the image.
pixel_t** allocateMemory(header_t header) {

  //Create variables, setting row to height and col to width
  int i;
  int row = header.height;
  int col = header.width;

  //Create pixel pointer
  pixel_t** pixels = (pixel_t**)malloc(row * sizeof(pixel_t*));

  //Loop through size of pixels, allocating memory for the ppm
  for (i = 0; i < row; i++) {
    pixels[i] = (pixel_t*)malloc(col * sizeof(pixel_t));
  }

//Return newly allocated pixels
return pixels;
}

//This function reads the values of the pixels from the ppm image.
pixel_t** readPixel(FILE* input, header_t header) {
  //Create variables and pixel pointer
  int row;
  int col;
  pixel_t** pix = allocateMemory(header);

  //Create rgb variables to place into pixel pointer
  unsigned char red = 0;
  unsigned char green = 0;
  unsigned char blue = 0;

  //HEIGHT FIRST (Learned my lesson) followed by width
  //Places pixels from input file into pixel pointer
  for (row = 0; row < header.height; row++) {
    for (col = 0; col < header.width; col++) {
      fscanf(input, "%c%c%c", &red, &green, &blue);
      pix[row][col].r = red;
      pix[row][col].g = green;
      pix[row][col].b = blue;
    }
  }

  //Return the pixels to driver
  return pix;
}

//This function will be used to write the pixels to the output ppm file.
void writePixels(FILE* out, pixel_t** pixels, header_t header) {
  //Confirm that the header's magic number will be P6
  header.magicNum[1] = '6';
  //Write header to output file
  writeHeader(out, header);

  //Print the pixels to the output (HEIGHT FIRST)
  int i, j;
  for (i = 0; i < header.height; i++) {
    for (j = 0; j < header.width; j++) {
      fprintf(out, "%c%c%c", pixels[i][j].r, pixels[i][j].g, pixels[i][j].b);
    }
  }
}

//Will be use to subtract the value of the ones place of each rgb in the pixel.
void removeDigit(pixel_t** pixels, header_t header) {
  //Create variables and loop through pixels
  int i, j;
  for (i = 0; i < header.height; i++) {
    for (j = 0; j < header.width; j++) {
      //Algorithm to replace last digit of r, g, and b with 0
      pixels[i][j].r = pixels[i][j].r - (pixels[i][j].r % 10);
      pixels[i][j].g = pixels[i][j].g - (pixels[i][j].g % 10);
      pixels[i][j].b = pixels[i][j].b - (pixels[i][j].b % 10);
    }
  }
}

//This function will add a 1 or a 0 to the value of r,g,b for the pixel
void encodeMsg(FILE* out, header_t header, pixel_t** pixels, char* message) {
  int i, j, dec;
  int arr[9];
  int charCount = 0;

  //Find the length of the encoded message
  int length = strlen(message);

  int a = 0;
  int bits = 0;
  //Begin loop to encode image
  for (i = 0; i < header.height; i++) {
    //First step is to fill the array with
    //the binary equivalent of the character
    dec = message[charCount];
    dec2bin(arr, dec);
    for (j = 0; j < header.width; j++) {
      if (a < length && bits < 9) {
        //Then fill the r, g, and b values with
        //the consecutive 3 binary values
        pixels[i][j].r = pixels[i][j].r + arr[bits];
        bits++;
        pixels[i][j].g = pixels[i][j].g + arr[bits];
        bits++;
        pixels[i][j].b = pixels[i][j].b + arr[bits];
        bits++;
      }
    }
    a += 1;
    charCount++;
  }

  //Writing encoded pixels and header to output
  writePixels(out, pixels, header);
}

//Converts a decimal number to binary
void dec2bin(int arr[9], int b) {
  int x;

  for (x = 8; x >= 0; x--) {
    arr[x] = b % 2;

    if (b > 0) {
      b = b / 2;
    }
    else {
      arr[x] = 0;
    }
  }
}
