//Name:         Patrick Woodrum
//Instructor:   Brygg Ullmer
//Class:        3220
//Date:         11/10/2020
//File:         main.cpp

// Base code by Bidur Bohara (LSU) in collaboration with Brygg Ullmer

//#include <QCoreApplication>
#include <vector>
#include <math.h>
#include "cscbitmap.h"
#include <stdio.h>
#include <pthread.h>

int sobel_x[3][3] = { { 1, 0,-1},
                      { 2, 0,-2},
                      { 1, 0,-1}};

int sobel_y[3][3] = { { 1, 2, 1},
                      { 0, 0, 0},
                      {-1,-2,-1}};

/// Declaration of functions.
void* findEdge(const unsigned int w, const unsigned int h);

/// Memory to hold input image data
unsigned char* inData;
std::vector<unsigned char> image_sobeled;

//Global Variable for thread creation
int a = 2;

// Qt entry point!
// Create and run a thread inside main function.
// Also assign region of image to a thread, and 
// call thread join for synchronization.
int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    char* bmpFile;
    if( argc < 2)
      {
	      printf("Filename argument required!\n");
	      return 0;
      }
    else
      {
      bmpFile = argv[1]; 
      }

    int numThreads = atoi(argv[2]);
    
    //Create thread and make it joinable
    //Declare variable for thread ID
    int rc, i;
    pthread_t threads[numThreads];

    //Init struct to hold region for reading
    struct Region whatToRead;

    /// Open and read bmp file.
    Bitmap *image = new Bitmap();
    unsigned char*data = image->readGrayBitmap(bmpFile);

    image_sobeled.clear();
    image_sobeled.resize(image->bmpSize, 255);
    inData = data;

    //Assign bmp data to struct values
    whatToRead.w = image->bmpWidth;
    whatToRead.h = image->bmpHeight;

    //Create the thread and send the struct with w and h to function
    for (i = 0; i < numThreads; i++) 
    {
      rc = pthread_create(&threads[i], NULL, findEdge, (void *)&whatToRead);
    }

    /// Write image data passed as argument to a bitmap file
    image->writeGrayBmp(&image_sobeled[0]);
    image_sobeled.clear();
    delete data;

    return 0;
    //return a.exec();
}


/// Function that implements Sobel operator.
/// Returns image data after applying Sobel operator to the original image.
/// Reimplement findEdge such that it will run in a single thread
/// and can process on a region/group of pixels
void* findEdge(void *region)
{
    int gradient_X = 0;
    int gradient_Y = 0;
    int value = 0;

    //Assign w and h to region's width and height
    const unsigned int w = region.w;
	  const unsigned int h = region.h;

    // The FOR loop apply Sobel operator
    // to bitmap image data in per-pixel level.
    for(unsigned int y = 1; y < h-1; ++y)
        for(unsigned int x = 1; x < w-1; ++x)
        {
            // Compute gradient in +ve x direction
            gradient_X = sobel_x[0][0] * inData[ (x-1) + (y-1) * w ]
                    + sobel_x[0][1] * inData[  x    + (y-1) * w ]
                    + sobel_x[0][2] * inData[ (x+1) + (y-1) * w ]
                    + sobel_x[1][0] * inData[ (x-1) +  y    * w ]
                    + sobel_x[1][1] * inData[  x    +  y    * w ]
                    + sobel_x[1][2] * inData[ (x+1) +  y    * w ]
                    + sobel_x[2][0] * inData[ (x-1) + (y+1) * w ]
                    + sobel_x[2][1] * inData[  x    + (y+1) * w ]
                    + sobel_x[2][2] * inData[ (x+1) + (y+1) * w ];

            // Compute gradient in +ve y direction
            gradient_Y = sobel_y[0][0] * inData[ (x-1) + (y-1) * w ]
                    + sobel_y[0][1] * inData[  x    + (y-1) * w ]
                    + sobel_y[0][2] * inData[ (x+1) + (y-1) * w ]
                    + sobel_y[1][0] * inData[ (x-1) +  y    * w ]
                    + sobel_y[1][1] * inData[  x    +  y    * w ]
                    + sobel_y[1][2] * inData[ (x+1) +  y    * w ]
                    + sobel_y[2][0] * inData[ (x-1) + (y+1) * w ]
                    + sobel_y[2][1] * inData[  x    + (y+1) * w ]
                    + sobel_y[2][2] * inData[ (x+1) + (y+1) * w ];

            value = (int)ceil(sqrt( gradient_X * gradient_X +
                                    gradient_Y * gradient_Y));
            image_sobeled[ x + y*w ] = 255 - value;
        }
    // Visual Studio requires this to be present; and should not 
    // cause issues for other compilers. 
    // Thanks to Thomas Peters.

    //Exit the thread before returning
    pthread_exit(NULL);
    return 0;
}
