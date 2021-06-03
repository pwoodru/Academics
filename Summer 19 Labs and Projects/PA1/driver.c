/*******************
Patrick Woodrum
CpSc 1020 Sm19
pwoodru@clemson.edu
********************/

#include <stdio.h>
#include <stdlib.h>
#include "encode.h"

int main (int argc, char* argv[]) {

  //Check that the user entered enough command line arguments
  if (argc < 3) {
    printf("Not enough arguments. This program requires the executable, ");
    printf("an input file, and an output file.\n");

    return -1;
  }

  //Create input file pointer
  FILE* input = fopen(argv[1], "r");
  //Check that input opened
  if (input == NULL) {
    printf("Input could not be opened\n");
    return -1;
  }

  //Create output file pointer
  FILE* out = fopen(argv[2], "w");
  //Check that output opened
  if (out == NULL) {
    printf("Output could not be opened\n");
    return -1;
  }

  //PROGRAM BEGINS WORKING HERE
  //Create header variable and read input file information into it
  header_t imageHeader;
  readHeader(input, &imageHeader);

  //Create allocated double pointer to hold pixels
  pixel_t** pixels = readPixel(input, imageHeader);

  //Create a character pointer for the message to be encoded in the image.
  char* encodedMessage = "Fun";

  //Replace the ones digits with zeroes to prep for encoding
  removeDigit(pixels, imageHeader);

  //Encode the image with the secret message
  //This function also writes the image to the output.
  encodeMsg(out, imageHeader, pixels, encodedMessage);

  //free memory and close files
  int i;
  for (i = 0; i < imageHeader.height; i++) {
    free(pixels[i]);
  }
  free(pixels);

  fclose(input);
  fclose(out);


return 0;
}
