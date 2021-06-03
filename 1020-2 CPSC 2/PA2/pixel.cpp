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

Pixel::Pixel(int a, int b, int c) {
  this->red = a;
  this->green = b;
  this->blue = c;
}

int Pixel::get_red() const {
  return this->red;
}

void Pixel::set_red(int red) {
  this->red = red;
}

int Pixel::get_green() const {
  return this->green;
}

void Pixel::set_green(int green) {
  this->green = green;
}

int Pixel::get_blue() const {
  return this->blue;
}

void Pixel::set_blue(int blue) {
  this->blue = blue;
}
