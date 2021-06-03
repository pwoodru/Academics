/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "triangle.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Triangle::Triangle() {
  point1.setX(0);
  point1.setY(0);

  point2.setX(0);
  point2.setY(0);

  point3.setX(0);
  point3.setY(0);
}

void Triangle::setPoint(vector <Point> pts) {
  //Create an instance of the Point class (your choice of point value)
  Point p1, p2, p3;

  p1.setX(pts.at(0).getX());
  p1.setY(pts.at(0).getY());
  this->point1 = p1;

  p2.setX(pts.at(1).getX());
  p2.setY(pts.at(1).getY());
  this->point2 = p2;

  p3.setX(pts.at(2).getX());
  p3.setY(pts.at(2).getY());
  this->point3 = p3;
}

    /*test is used to test each pixel of the image. Remember you are
    *trying to determine if test (which is a point) is within the three points
    *of the triangle*/

bool Triangle::isHit(Point& p) {
  //Set the X and Y values to the test Point
  int hit = triCheckPoint(point1, point2, point3, p);
    if (hit == 1) {
      return 1;
    }
    else {
      return 0;
    }
}

void Triangle::draw(Image& imageTri, ifstream& input) {
  int row, col;
  int plot;

  //Simple workaround for my problem, read input for color, set color, and
  //call color all in the draw function LATER EDIT: WORKS!
  int r, g, b;
  //Read r, g, b pixels into ints
  input >> r >> g >> b;
  //Set ints equal to corresponding color values
  Color triCol((unsigned char)r, (unsigned char)g, (unsigned char)b);

  for (col = 0; col < imageTri.getHeaderHeight(); col++) {    //GET header, col first, row
    for (row = 0; row < imageTri.getHeaderWidth(); row++) {
      Point temp(row, col);
      plot = isHit(temp);                              //FLAG

      //If test point is within circle
      if (plot) {
        imageTri.getPixel().at(row).at(col).set_red(triCol.getrNum());
        imageTri.getPixel().at(row).at(col).set_green(triCol.getgNum());
        imageTri.getPixel().at(row).at(col).set_blue(triCol.getbNum());
      }
      //If test point is not within circle
      else {
        imageTri.getPixel().at(row).at(col).set_red(0);
        imageTri.getPixel().at(row).at(col).set_green(0);
        imageTri.getPixel().at(row).at(col).set_blue(0);
      }
    }
  }
  //Erase all values inside vector <Point> pts from shape class
  //This makes it easier to read input into vector for a new shape
  pts.clear();
}

void Triangle::readInfo(ifstream& input) {
  //Create variables to read points into
  int p1int, p1int2, p2int, p2int2, p3int, p3int2;
  //Read from input
  input >> p1int >> p1int2 >> p2int >> p2int2 >> p3int >> p3int2;

  //Create Point instances for the variables
  //Set the Triangle's Points with the newly created Points
  Point pt1(p1int, p1int2);
  Point pt2(p2int, p2int2);
  Point pt3(p3int, p3int2);

  //Set the Points into the Point vector provided by Shape
  pts.push_back(pt1);
  pts.push_back(pt2);
  pts.push_back(pt3);
}
