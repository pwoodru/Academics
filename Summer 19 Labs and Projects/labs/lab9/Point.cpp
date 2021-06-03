#include "point.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void Point::setX(int x) { //Set x
  this->x = x;
}

void Point::setY(int y) { //Set y
  this->y = y;
}

int Point::getX() { //Get the previously set x
  return this->x;
}

int Point::getY() { //Get the previously set y
  return this->y;
}
