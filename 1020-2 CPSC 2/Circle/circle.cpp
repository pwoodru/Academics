/*******************
Patrick Woodrum
pwoodru Section 3
Lab 9
TA: Nushrat Humaira
********************/

#include "Circle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

//Constructor
Circle::Circle() {
  radius = 0;
  centerX = 0;
  centerY = 0;
}

//Regular Constructor
Circle::Circle(int a, int b, int c) {
  this->radius = a;
  this->centerX = b;
  this->centerY = c;
}

//Hit function found in circle class
int Circle::hit(int x, int y) {
  int hitCheck = sqrt(pow(x - centerX, 2) + pow(y - centerY, 2));

  if (hitCheck <= radius) {
    return 1;
  }
  else {
    return 0;
  }
}

//Fill vector function found in circle class
void fillVec(vector< vector<Pixel> >& vec2D, Circle& cir) {
    unsigned int a, b;
    int plot;

    for (a = 0; a < vec2D.size(); a++) {
      for (b = 0; b < vec2D[a].size(); b++) {
        plot = cir.hit(b, a);

        //If test point is within circle
        if (plot) {
          vec2D.at(a).at(b).r = 82;
          vec2D.at(a).at(b).g = 45;
          vec2D.at(a).at(b).b = 128;

        }
        //If test point is not within circle
        else {
          vec2D.at(a).at(b).r = 246;
          vec2D.at(a).at(b).g = 102;
          vec2D.at(a).at(b).b = 51;

        }
      }
    }

}

//Print vector function found in circle class
void printVec(ofstream& output, vector< vector<Pixel> >& img, int row, int col)
{
  //Print header to file first
  output << "P6" << endl << col << " " << row << " " << "255" << endl;

  //Print pixels from inside vector
  unsigned int i, j;
  for (i = 0; i < img.size(); i++) {
    for (j = 0; j < img[i].size(); j++) {
      output << img.at(i).at(j).r;
      output << img.at(i).at(j).g;
      output << img.at(i).at(j).b;
    }
  }
}
