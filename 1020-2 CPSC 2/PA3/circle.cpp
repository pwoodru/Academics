/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "circle.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


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
bool Circle::isHit(Point& p) {
  int hitCheck = sqrt(pow(p.getX() - pts.at(0).getX(), 2) + pow(p.getY() - pts.at(0).getY(), 2));

  if (hitCheck <= radius) {
    return 1;
  }
  else {
    return 0;
  }
}

//Fill vector function found in circle class
void Circle::draw(Image& imageCir, ifstream& input) {
    int row, col;
    int plot;

    //Simple workaround for my problem, read input for color, set color, and
    //call color all in the draw function LATER EDIT: WORKS!
    int r, g, b;
    //Read r, g, b pixels into ints
    input >> r >> g >> b;
    //Set ints equal to corresponding color values
    Color cirCol((unsigned char)r, (unsigned char)g, (unsigned char)b);

    //Loop through vector, testing each pixel with Circle Point
    for (col = 0; col < imageCir.getHeaderHeight(); col++) {
      for (row = 0; row < imageCir.getHeaderWidth(); row++) {
        Point temp(row, col);
        plot = isHit(temp);
        //If test point is within circle
        if (plot) {
          imageCir.getPixel().at(row).at(col).set_red(cirCol.getrNum());
          imageCir.getPixel().at(row).at(col).set_green(cirCol.getgNum());
          imageCir.getPixel().at(row).at(col).set_blue(cirCol.getbNum());
        }
        //If test point is not within circle
        else {
          imageCir.getPixel().at(row).at(col).set_red(0);
          imageCir.getPixel().at(row).at(col).set_green(0);
          imageCir.getPixel().at(row).at(col).set_blue(0);
        }
      }
    }

    //Erase all values inside vector <Point> pts from shape class
    //This makes it easier to read input into vector for a new shape
    pts.clear();
}

void Circle::readInfo(ifstream& input) {
  //Create integers to read values into
  int xVal, yVal, rad;

  //Create a Point to later set values equal to
  Point p;

  //Read values into integers from input
  input >> xVal >> yVal >> rad;

  //Set circle values from values that were just read in
  this->centerX = xVal;
  this->centerY = yVal;
  this->radius = rad;

  //Set the Point values and call setPoint to set them into the vector
  //inherited through the Shape class
  p.setX(xVal);
  p.setY(yVal);
  pts.push_back(p);
}

void Circle::setPoint(vector <Point> pts) {
  Point p1;
  p1.setX(centerX);
  p1.setY(centerY);
}
