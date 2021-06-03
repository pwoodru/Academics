/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include "point.h"
#include "pixel.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

class Circle: public Shape
{
    private:
      int centerX;
      int centerY;
      int radius;

    public:
      Circle();
      Circle(int, int, int);
      bool isHit(Point&);
      void readInfo(ifstream& input);
      void setPoint(vector <Point>);
      vector<Point> getPoints()const {return pts;}
      void draw(Image&, ifstream&);

};

#endif
