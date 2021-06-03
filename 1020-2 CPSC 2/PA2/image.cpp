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

Image Image::read_pixels(ifstream& input, Header header, vector<vector<Pixel> >& vec) {
  unsigned int a, b;
  unsigned char red, green, blue;
  red = 0;
  green = 0;
  blue = 0;

  for(a = 0; a < vec.size(); a++) {
    for(b = 0; b < vec[a].size(); b++) {
      input >> red;
      vec.at(a).at(b).set_red(red);

      input >> green;
      vec.at(a).at(b).set_green(green);

      input >> blue;
      vec.at(a).at(b).set_blue(blue);
    }
  }

  Image image(vec, header);

return image;
}


void Image::write_p6(ofstream& out, Image image) {
  out << "P6" << endl << "800 " << "600" << endl << "255" << endl;

  unsigned int i, j;
  for (i = 0; i < pixVec.size(); i++) {
    for (j = 0; j < pixVec[i].size(); j++) {
      out << pixVec.at(i).at(j).get_red();
      out << pixVec.at(i).at(j).get_green();
      out << pixVec.at(i).at(j).get_blue();
    }
  }
}
