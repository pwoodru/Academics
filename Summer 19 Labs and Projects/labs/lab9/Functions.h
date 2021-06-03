/*These functions are not part of the class but helper functions or fuctions
 *that use the circle class*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Circle.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Pixel{
  unsigned char r, g, b;
};
void fillColor(vector< vector<Pixel> >& vec2D);
void fillCircle(vector< vector<Pixel> >& vec2D, Circle& cir);
void printVec(ofstream& output, vector< vector<Pixel> > &vec, int row, int col);

#endif
