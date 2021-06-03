/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "color.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

//Default constructor
Color::Color() {
  rNum = 145;
  gNum = 230;
  bNum = 75;
}

//Regular Constructor
Color::Color(unsigned char x, unsigned char y, unsigned char z) {
  this->rNum = x;
  this->gNum = y;
  this->bNum = z;
}

//Destructor
Color::~Color() {
}

//Set red
void Color::setrNum(unsigned char x) {
  //cout << (int)x << endl;
  this->rNum = x;
}

//Set green
void Color::setgNum(unsigned char y) {
  this->gNum = y;
}

//Set blue
void Color::setbNum(unsigned char z) {
  //cout << (int)z << endl;
  this->bNum = z;
}

//Get red
unsigned char Color::getrNum() const {
  return this->rNum;
}

//Get green
unsigned char Color::getgNum() const {
  return this->gNum;
}

//Get blue
unsigned char Color::getbNum() const {
  return this->bNum;
}
/*
void Color::readInfo(ifstream& input) {
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
*/
