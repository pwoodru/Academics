/****************
Patrick Woodrum
pwoodru
CpSc 1020 Sm19
Lab 4
TA: Nushrat H
****************/

#include <stdio.h>
#include <stdlib.h>
#include "ppm_info.h"

//reads the input file's header and transfers to local header
header_t read_header(FILE* image_file) {
  header_t header;
  fscanf(image_file, "%s ", header.magicNum);
  fscanf(image_file, "%d %d ", &header.width, &header.height);
  fscanf(image_file, "%d ", &header.maxVal);

  return header;
}

//writes header to the output file
void write_header(FILE* out_file, header_t header) {
  fprintf(out_file, "%s %d ", header.magicNum, header.width);
  fprintf(out_file, "%d %d\n", header.height, header.maxVal);
}

//mother function of read_pixels, reads the header as well as pixels
image_t* read_ppm(FILE* image_file) {
  header_t header = read_header(image_file);

  image_t* image = read_pixels(image_file, header);

  if (!image) {
    printf("Image failed to read.\n");
  }

  return image;
}

//takes the input file and reads the pixels into the created image
image_t* read_pixels(FILE* image_file, header_t header) {
  int row;
  int col;

  //allocate memory for the image
  image_t* image = allocate_memory(header);

  unsigned char red, green, blue;
  red = 0;
  green = 0;
  blue = 0;

  //iterate through and transfer pixels to the image
  for (row = 0; row < header.height; row++) {
    for (col = 0; col < header.width; col++) {
      fscanf(image_file, "%c%c%c", &red, &green, &blue);
      image->pixels[row][col].r = red;
      image->pixels[row][col].g = green;
      image->pixels[row][col].b = blue;
    }
  }
  return image;
}

//responsible for allocating the memory for an image_t
image_t* allocate_memory(header_t header) {

  //allocate the image to use
  image_t* image = (image_t*)malloc(sizeof(image_t));

  //set image info and allocate
  image->header = header;
  image->pixels = (pixel_t**)malloc(header.height * sizeof(pixel_t*));

  //loop and allocate the rest of the image
  int i;
  for (i = 0; i < header.height; i++) {
    image->pixels[i] = (pixel_t*)malloc(header.width * sizeof(pixel_t));
  }

  return image;
}

//write the pixels to the out_file in P6 format
void write_p6(FILE* out_file, image_t* image) {
  header_t header = image->header;

  //make sure magicnum is p6
  header.magicNum[1] = '6';
  write_header(out_file, header);

  //loop and print pixels to output file
  int i, j;
  for (i = 0; i < header.height; i++) {
    for (j = 0; j < header.width; j++) {
      fprintf(out_file, "%c", image->pixels[i][j].r);
      fprintf(out_file, "%c", image->pixels[i][j].g);
      fprintf(out_file, "%c", image->pixels[i][j].b);
    }
  }
}

//write the pixels to the out_file in p3 format
void write_p3(FILE* out_file, image_t* image) {
  header_t header = image->header;

  //make sure magicnum is p3
  header.magicNum[1] = '3';
  write_header(out_file, header);

  //loop and print pixels to output file
  int i, j;
  for (i = 0; i < header.height; i++) {
    for (j = 0; j < header.width; j++) {
      fprintf(out_file, "%d ", image->pixels[i][j].r);
      fprintf(out_file, "%d ", image->pixels[i][j].g);
      fprintf(out_file, "%d ", image->pixels[i][j].b);
    }
  }
}
