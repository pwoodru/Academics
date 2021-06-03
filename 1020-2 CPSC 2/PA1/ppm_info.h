/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/
#ifndef PPM_INFO
#define PPM_INFO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct Definitions
typedef struct header {
  char magicNum[3];
  int width, height, maxVal;
} header_t;

typedef struct pixel {
  unsigned int r, g, b;
} pixel_t;

typedef struct image {
  header_t header;
  pixel_t** pixels;
} image_t;


//Prototypes

/*Image Resize
*Parameters - two image_t* files containing original image and resized image
*return - no return
*This function resizes the pixels in the original image to create the resized image
*/
void resizeImage(image_t*, image_t*);

/*Read header
*Parameters - one file pointer to the input file
*return - header_t header read from the input
*This function reads the header from the input and returns the header
*/
header_t read_header(FILE*);

/*Write header
*Parameters - an out file pointer and a header
*return - no return
*This function takes the header that was read from a previous function
*and outputs it to the out file
*/
void write_header(FILE* out_file, header_t header);

/*Write P6
*Parameters - an out file pointer and an image pointer
*return - no return
*This function will take a created image and write it to an output file as P6.
*/
void write_p6(FILE* out_file, image_t* image);

/*Read in the image
*Parameters - file pointer to the input image
*return - the image received from input
*This function reads an input file's header and pixel information
*and returns it as a usable image
*/
image_t* read_ppm(FILE* image_file);

/*Read in pixels
*Parameters - an input file pointer and a header
*return - an image
*This function is used within read_ppm and is primarily for retrieving the pixel
*information from an input file
*/
image_t* read_pixels(FILE* image_file, header_t header);

/*Allocate memory for image
*Parameters - a header for an image
*return - newly allocated image
*This function is used to allocate enough memory to create an image. It is crucial to
*creating images and storing information
*/
image_t* allocate_memory(header_t header);

/*Grayscale an image
*Parameters - an image pointer
*return - no return
*This function receives a colorized image and changes each pixel color to
*relative shades of gray
*/
void grayscale(image_t* image);

/*Create picture collage
*Parameters - an output file pointer and two image pointers
*return - no return
*This function receives two images and creates a new image with
*the second image on top
*/
void writeCollage(FILE* out, image_t* image, image_t* resizedimage);

#endif
