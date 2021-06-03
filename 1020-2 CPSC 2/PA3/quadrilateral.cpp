/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "quadrilateral.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Quadrilateral::Quadrilateral() {
  q1.setX(0);
  q1.setY(0);

  q2.setX(0);
  q2.setY(0);

  q3.setX(0);
  q3.setY(0);

  q4.setX(0);
  q4.setY(0);
}

void Quadrilateral::setPoint(vector <Point> pts) {
  //Create an instance of the Point class (your choice of point value)
  Point p1, p2, p3, p4;

  p1.setX(pts.at(0).getX());
  p1.setY(pts.at(0).getY());
  this->q1 = p1;

  p2.setX(pts.at(1).getX());
  p2.setY(pts.at(1).getY());
  this->q2 = p2;

  p3.setX(pts.at(2).getX());
  p3.setY(pts.at(2).getY());
  this->q3 = p3;

  p4.setX(pts.at(3).getX());
  p4.setY(pts.at(3).getY());
  this->q4 = p4;
}

bool Quadrilateral::isHit(Point& p) {
  //Testing the input Point 'p' for a hit inside three triangles that make up
  //the quadrilateral I want to create
  int hit1 = triCheckPoint(q1, q2, q4, p);
  int hit2 = triCheckPoint(q1, q3, q4, p);
  int hit3 = triCheckPoint(q2, q3, q4, p);
  int hit = hit1 + hit2 + hit3;
    if (hit == 3) {
      return 1;
    }
    else {
      return 0;
    }
}

void Quadrilateral::draw(Image& imageQuad, ifstream& input) {
  int row, col;
  int plot;

  //Simple workaround for my problem, read input for color, set color, and
  //call color all in the draw function LATER EDIT: WORKS!
  int r, g, b;
  //Read r, g, b pixels into ints
  input >> r >> g >> b;
  //Set ints equal to corresponding color values
  Color quadCol((unsigned char)r, (unsigned char)g, (unsigned char)b);

  for (col = 0; col < imageQuad.getHeaderHeight(); col++) {
    for (row = 0; row < imageQuad.getHeaderWidth(); row++) {
      Point temp(row, col);
      plot = isHit(temp);

      //If test point is within circle
      if (plot) {
        imageQuad.getPixel().at(row).at(col).set_red(quadCol.getrNum());
        imageQuad.getPixel().at(row).at(col).set_green(quadCol.getgNum());
        imageQuad.getPixel().at(row).at(col).set_blue(quadCol.getbNum());
      }
      //If test point is not within circle
      else {
        imageQuad.getPixel().at(row).at(col).set_red(0);
        imageQuad.getPixel().at(row).at(col).set_green(0);
        imageQuad.getPixel().at(row).at(col).set_blue(0);
      }
    }
  }
  //Erase all values inside vector <Point> pts from shape class
  //This makes it easier to read input into vector for a new shape
  pts.clear();
}

void Quadrilateral::readInfo(ifstream& input) {
  //Create variables to read points into
  int q1int, q1int2, q2int, q2int2, q3int, q3int2, q4int, q4int2;;
  //Read from input
  input >> q1int >> q1int2 >> q2int >> q2int2 >> q3int >> q3int2 >> q4int
  >> q4int2;

  //Create Point instances for the variables
  //Set the Quad's Points with the newly created Points
  Point pt1(q1int, q1int2);
  Point pt2(q2int, q2int2);
  Point pt3(q3int, q3int2);
  Point pt4(q4int, q4int2);

  //Set the Points into the Point vector provided by Shape
  pts.push_back(pt1);
  pts.push_back(pt2);
  pts.push_back(pt3);
  pts.push_back(pt4);
}
