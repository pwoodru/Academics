/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef POINT_H
#define POINT_H
#include "pixel.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;


//Class Definition
class Point {

private:
  double x, y;

public:

  Point(); //Constructor
  Point(double x, double y); //Regular constructor

  ~Point(); //Destructor

  void setX(double x);
  void setY(double y);

  double getX();
  double getY();
};

//Function Prototype
int triCheckPoint(Point, Point, Point, Point);


#endif
