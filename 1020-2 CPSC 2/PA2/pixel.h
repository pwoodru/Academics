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
      int red;
      int green;
      int blue;

    public:
      Pixel();
      Pixel(int, int, int);

      int get_red() const;
      void set_red(int red);

      int get_green() const;
      void set_green(int green);

      int get_blue() const;
      void set_blue(int blue);
};

#endif
