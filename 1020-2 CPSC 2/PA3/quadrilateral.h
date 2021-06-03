/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include "shape.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Quadrilateral: public Shape
{
    private:
      Point q1;
      Point q2;
      Point q3;
      Point q4;

    public:
      Quadrilateral();
      Quadrilateral(Point, Point, Point, Point);
      bool isHit(Point& p);
      void readInfo(ifstream& input);
      void setPoint(vector <Point>);
      void draw(Image&, ifstream&);

};

#endif
