/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include <iostream>
#include <fstream>
#include "point.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

Point::Point() { //Constructor
  x = 0;
  y = 0;
}

Point::Point(double x, double y) { //Regular Constructor
  this->x = x;
  this->y = y;
}

void Point::setX(double x) { //Set x
  this->x = x;
}

void Point::setY(double y) { //Set y
  this->y = y;
}

double Point::getX() { //Get the previously set x
  return this->x;
}

double Point::getY() { //Get the previously set y
  return this->y;
}

Point::~Point() { //Destructor
}

int triCheckPoint(Point P1, Point P2, Point P3, Point PCheck) {
  double a, b, c;
  double denominator, a1, b1;

  denominator = ((P2.getY() - P3.getY())*(P1.getX() - P3.getX()) + (P3.getX() - P2.getX()) * (P1.getY() - P3.getY()));

  a1 = ((P2.getY() - P3.getY())*(PCheck.getY() - P3.getY()) + (P3.getX() - P2.getX()) * (PCheck.getY() - P3.getY()));
  a = a1 / denominator;

  b1 = ((P3.getY() - P1.getY())*(PCheck.getX() - P3.getX()) + (P1.getX() - P3.getX()) * (PCheck.getY() - P3.getY()));
  //b2 = ((P2.y - P3.y)*(P1.x - P3.x) + (P3.x - P2.x) * (P1.y - P3.y));
  b = b1 / denominator;

  c = 1 - a - b;

  if ((0 < a) && (a < 1) && (0 < b) && (b < 1) && (0 < c) && (c < 1)) {
    return 1;
  }
  else {
    return 0;
  }
}
