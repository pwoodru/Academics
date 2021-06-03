/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include <stdio.h>
#include <stdlib.h>
#include "ppm_info.h"

void resizeImage(image_t* input, image_t* resizedimage) {
  double relativewidth, relativeheight;
  int row, col;

  int desiredwidth = 600;
  int desiredheight = 600;

  header_t header = input->header;

  relativewidth = (double)header.width / desiredwidth;
  relativeheight = (double)header.height / desiredheight;

  for (row = 0; row < desiredheight; row++) {  //height
				for (col = 0; col < desiredwidth; col++) {  //width
            resizedimage->pixels[row][col] = input->pixels[(int)(row*relativeheight)][(int)(col*relativewidth)];
          }
        }
}

header_t read_header(FILE* input) {
  header_t header;

	fscanf(input, "%s ",     header.magicNum);
	fscanf(input, "%d %d ", &header.width, &header.height);
	fscanf(input, "%d ",    &header.maxVal);

return header;
}

void write_header(FILE* out, header_t header) {
	fprintf(out, "%s %d %d %d ", header.magicNum, header.width, header.height, header.maxVal);
}

//Read Pixels
image_t* read_pixels(FILE* input, header_t header) {
	int row;
	int col;
	///declare red, green, blue as unsigned char
	///initialize red, green, blue as 0;

	//Allocate for image
	image_t* image = allocate_memory(header);

			unsigned char red, green, blue;
			red = 0;
			green = 0;
			blue = 0;

			for (row = 0; row < header.height; row++) {//height
				for (col = 0; col < header.width; col++) {//width
					fscanf(input, "%c%c%c", &red, &green, &blue);
					image->pixels[row][col].r = red;
					image->pixels[row][col].g = green;
					image->pixels[row][col].b = blue;
				}
			}
return image;
}

//Read Image
image_t* read_ppm(FILE* input) {
	header_t header = read_header(input);

	image_t* image = read_pixels(input, header);

	if (!image) {
		printf("image could not be read.\n");
	}

return image;
}

//Allocate memory for pixels
image_t* allocate_memory(header_t header) {

	//Allocate image memory
	image_t* image = (image_t*)malloc(sizeof(image_t));

	//Set image information
	image->header = header;
	image->pixels = (pixel_t**)malloc(sizeof(pixel_t*) * header.height);

	int row;
	for (row = 0; row < header.height; row++) {
			image->pixels[row] = (pixel_t*)malloc(sizeof(pixel_t) * header.width);
	}

return image;
}

//Write P6
void write_p6(FILE* out, image_t* image) {
	header_t header = image->header;

	//Change Magic Number to 6
	header.magicNum[1] = '6';
	write_header(out, header);

	//Write image to P6
	int a, b;
	for (a = 0; a < header.height; a++) {
		for (b = 0; b < header.width; b++) {
			fprintf(out, "%c%c%c", image->pixels[a][b].r, image->pixels[a][b].g, image->pixels[a][b].b);
	  }
  }
}

void grayscale(image_t* image) {
	
	int i, j;
	int rgbSum = 0;
	header_t header = image->header;

	//Sum RGB values into one integer
	for (i = 0; i < header.width; i++) {
		for (j = 0; j < header.height; j++) {
			rgbSum += image->pixels[i][j].r;
			rgbSum += image->pixels[i][j].g;
			rgbSum += image->pixels[i][j].b;
			
			//Create grayscale color
			rgbSum = rgbSum / 3;
			//Set pixels equal to grayscale
			image->pixels[i][j].r = rgbSum;
			image->pixels[i][j].g = rgbSum;
			image->pixels[i][j].b = rgbSum;
		}
	}
}

void writeCollage(FILE* out, image_t* image, image_t* resizedimage) {
	
	//Read in header information from original
	header_t header = image->header;

	//Make sure file is P6
	header.magicNum[1] = '6';
	write_header(out, header);

	//Print original image to output
	int i, j;

	for(i = 0; i < header.height; i++) {
		for(j = 0; j < header.width; j++) {
			//Print new image over old image
			if (j < 600) {
				fprintf(out, "%c%c%c", resizedimage->pixels[i][j].r, resizedimage->pixels[i][j].g, resizedimage->pixels[i][j].b);
			}
			else {
				fprintf(out, "%c%c%c", image->pixels[i][j].r, image->pixels[i][j].g, image->pixels[i][j].b);
			}
		}
	}
}	















