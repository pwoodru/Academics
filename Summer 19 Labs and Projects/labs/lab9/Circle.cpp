#include "circle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

//Constructor
Circle::Circle() {
  radius = 0;
  center.setY(0);
  center.setX(0);
}

Circle::Circle(Point& p, int a) {
  this->radius = a;
  this->center.setX(p.getX());
  this->center.setY(p.getY());
}

int Circle::hit(Point&) {
  int hitCheck = sqrt(pow(p.getX() - pts.at(0).getX(), 2)
  + pow(p.getY() - pts.at(0).getY(), 2));

  if (hitCheck <= radius) {
    return 1;
  }
  else {
    return 0;
  }
}
Point Circle::getCenter() {
  return this->center;
}
