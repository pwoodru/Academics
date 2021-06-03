#include "Functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) {

  //open input
  ifstream input(argv[1]);
  //Input check
  if(!input) {
    cout << "Input file not opened" << endl;
    return -1;
  }

  //open output
  ofstream output(argv[2]);
  //Output check
  if(!output) {
    cout << "Output file not opened" << endl;
    return -1;
  }

  //Create input variables
  int rad, x, y, height, width;
  Point p;
  //read input into variables
  input >> rad >> x >> y >> height >> width;
  p.setX(x);
  p.setY(y);


  //Create circle
  Circle cir(p, rad);


  //Create 2D vector of pixels
  vector< vector<Pixel> > pix;
  //Resize to the size of the image
  pix.resize(height, vector<Pixel>(width));


  //Fill vector pixels with base color
  fillColor(pix);
  //Fill and create circle shape
  fillCircle(pix, cir);

  //Print image using created vector
  printVec(output, pix, height, width);

  //Close inputs and outputs
  input.close();
  output.close();


return 0;
}
