/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "image.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>


Image::Image() {
  Header header;

  vector<vector<Pixel> > pixVec;
}

Image::Image(vector<vector<Pixel> >& vec, Header header) {
  this->pixVec = vec;
  this->header = header;
}

void Image::write_img(ofstream& out, Image image) {
out << "P3" << endl << image.getHeaderHeight() << " " << image.getHeaderWidth()
      << endl << "255" << endl;

  int i, j;
  for (i = 0; i < image.getHeaderHeight(); i++) {
    for (j = 0; j < image.getHeaderWidth(); j++) {
      out << (int)pixVec.at(i).at(j).get_red() << " ";
      out << (int)pixVec.at(i).at(j).get_green() << " ";
      out << (int)pixVec.at(i).at(j).get_blue() << " ";
    }
  }
}

vector<vector<Pixel> >& Image::getPixel() {
  return pixVec;
}

int Image::getHeaderHeight() {
  int headheight = header.getHeight();
  return headheight;
}

int Image::getHeaderWidth() {
  int headwidth = header.getWidth();
  return headwidth;
}
