/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "pixel.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

Pixel::Pixel() {
  red = 0;
  green = 0;
  blue = 0;
}

Pixel::Pixel(unsigned char a, unsigned char b, unsigned char c) {
  this->red = a;
  this->green = b;
  this->blue = c;
}

unsigned char Pixel::get_red() const {
  return this->red;
}

void Pixel::set_red(unsigned char red) {
  this->red = red;
}

unsigned char Pixel::get_green() const {
  return this->green;
}

void Pixel::set_green(unsigned char green) {
  this->green = green;
}

unsigned char Pixel::get_blue() const {
  return this->blue;
}

void Pixel::set_blue(unsigned char blue) {
  this->blue = blue;
}
