/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.h"
#include "point.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Triangle: public Shape
{
    private:
      Point point1;
      Point point2;
      Point point3;

    public:
      Triangle();
      Triangle(Point, Point, Point);
      bool isHit(Point& p);
      void readInfo(ifstream& input);
      void setPoint(vector <Point>);
      void draw(Image&, ifstream&);

};

#endif
