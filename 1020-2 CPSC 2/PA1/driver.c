/*********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
***********************/
#include <stdio.h>
#include <stdlib.h>
#include "ppm_info.h"

int main(int argc, char* argv[]) {

  FILE* input;
  input = fopen(argv[1], "r");
	if (input == NULL) { //Checks if the file opened
		printf("Input could not open file\n");
		return -1;
	}
  FILE* out = fopen(argv[2], "w");
	if (input == NULL) { //Checks if the file opened
		printf("Output could not open file\n");
		return -1;
	}

  //Read the image into image_t
  image_t* image = read_ppm(input);

  //Make sure an image is loaded
  if (!image) {
	  printf("Input file could not be read.\n");
  return -1;
  }
  header_t newH = {"P6",600,600,255};
  image_t* resizedimage = allocate_memory(newH);

  resizeImage(image, resizedimage);

  grayscale(resizedimage);

  writeCollage(out, image, resizedimage);

  free(image->pixels);
  free(resizedimage->pixels);

  fclose(input);
  fclose(out);

return 0;
}
