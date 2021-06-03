/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef IMAGE_H
#define IMAGE_H
#include "pixel.h"
#include "header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

class Image
{
  private:
    vector<vector<Pixel> > pixVec;
    Header header;

  public:
    Image();
    Image(vector<vector<Pixel> >& vec, Header header);
    void write_img(ofstream& out, Image image);
    int getHeaderHeight();
    int getHeaderWidth();
    vector<vector<Pixel> >& getPixel();

};

#endif
