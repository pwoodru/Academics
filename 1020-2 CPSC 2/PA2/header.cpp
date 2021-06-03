/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "header.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

Header::Header() {
  MagicNum[0] = 'P';
  MagicNum[1] = '6';
  height = 800;
  width = 600;
  maxVal = 255;
}

Header::Header(int a, int b, int c) {
  MagicNum[0] = 'P';
  MagicNum[1] = '6';
  this->height = a;
  this->width = b;
  this->maxVal = c;
}

Header Header::read_header(ifstream& in) {
  Header header;

  in >> header.MagicNum;
  in >> header.height;
  in >> header.width;
  in >> header.maxVal;

  return header;
}

void Header::write_header(ofstream& out, Header header) {

  out << "%s" << MagicNum << endl << "%d" << height << " " << "%d" << width;
  out << " " << "%d" << maxVal << endl;

}
