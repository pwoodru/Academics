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

int main (int argc, char* argv[]) {

  //Command line amount check
  if (argc < 4) {
    printf("Not enough command line arguments. Exiting.\n");
    return -1;
  }

  //Input file check
  FILE* input = fopen(argv[1], "r");
  if (input == NULL) {
    printf("Input could not be opened\n");
    return -1;
  }

  //Output 1 file check
  FILE* out1 = fopen(argv[2], "w");
  if (out1 == NULL) {
    printf("Output 1 could not be opened\n");
    return -1;
  }

  //Output file 2 check
  FILE* out2 = fopen(argv[3], "w");
  if (out2 == NULL) {
    printf("Output 2 could not be opened\n");
    return -1;
  }

  //Create image and read from input
  image_t* image = read_ppm(input);
  if (!image) {
    printf("Input file did not open properly\n");
    return -1;
  }

  //Create header and read from input
  header_t header = read_header(input);

  //Write image to output 1 as P6
  write_p6(out1, image);

  //Write image to output 2 as P3
  write_p3(out2, image);

  //Free memory
  int i;
  for (i = 0; i < header.width; i++) {
    free(image->pixels[i]);
  }
  free(image->pixels);

  //Close inputs and outputs
  fclose(input);
  fclose(out1);
  fclose(out2);

return 0;
}
