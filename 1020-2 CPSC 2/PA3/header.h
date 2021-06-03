/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
using namespace std;

class Header
{
    private:
      char MagicNum[3];
      int height;
      int width;
      int maxVal;

    public:
      Header();
      Header(int, int, int);
      Header read_header(ifstream& in);
      void write_header(ofstream& out, Header header);
      int getHeight();
      int getWidth();
};

#endif
