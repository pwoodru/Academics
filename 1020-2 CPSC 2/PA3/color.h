/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef COLOR_H
#define COLOR_H
#include "image.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;


//Class Definition
class Color: public Image {

private:
  unsigned char rNum;
  unsigned char gNum;
  unsigned char bNum;

public:

  Color(); //Constructor
  Color(unsigned char x, unsigned char y, unsigned char z); //Reg constructor

  ~Color(); //Destructor

  //Setters
  void setrNum(unsigned char x);
  void setgNum(unsigned char y);
  void setbNum(unsigned char z);

  //Getters
  unsigned char getrNum() const;
  unsigned char getgNum() const;
  unsigned char getbNum() const;

  //void readInfo(ifstream& input);
};

#endif
