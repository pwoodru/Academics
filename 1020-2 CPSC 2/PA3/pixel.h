/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef PIXEL_H
#define PIXEL_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

class Pixel
{
    private:
      unsigned char red;
      unsigned char green;
      unsigned char blue;

    public:
      Pixel();
      Pixel(unsigned char, unsigned char, unsigned char);

      unsigned char get_red() const;
      void set_red(unsigned char red);

      unsigned char get_green() const;
      void set_green(unsigned char green);

      unsigned char get_blue() const;
      void set_blue(unsigned char blue);
};

#endif
