/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "shape.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

Shape::Shape() {

  name = "Shape";
  vector <Point> pts;

}

void Shape::setName(string Newname) {
  this->name = Newname;
}

string Shape::getName() const {
  return name;
}

void Shape::setColor(ifstream& input) {
  int r, g, b;
  //Read r, g, b pixels into ints
  input >> r >> g >> b;

  //Set ints equal to corresponding color values
  Color c((unsigned char)r, (unsigned char)g, (unsigned char)b);
  //cast to unsigned char
  //c.setrNum((unsigned char)r);
  //c.setgNum((unsigned char)g);
  //c.setbNum((unsigned char)b);
  //cout << r << endl;
  //cout << g << endl;
  //cout << (int)c.getbNum() << endl;
}
