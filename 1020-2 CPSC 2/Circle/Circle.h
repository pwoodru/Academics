/*******************
Patrick Woodrum
pwoodru Section 3
Lab 9
TA: Nushrat Humaira
********************/

#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
struct Pixel{
  unsigned char r, g, b;
};

class Circle
{
    private:
      int centerX;
      int centerY;
      int radius;

    public:
      Circle();
      Circle(int, int, int);
      int hit(int, int);

};

void fillVec(vector< vector<Pixel> >& vec2D, Circle& cir);
void printVec(ofstream& output, vector< vector<Pixel> >&, int, int);

#endif
