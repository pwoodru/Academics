/*******************
Patrick Woodrum
pwoodru Section 3
Lab 9
TA: Nushrat Humaira
********************/

#include "Circle.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

int main(int argc, char* argv[]) {

  //Input and Output
  ifstream input(argv[1]);
  //Input validity check
  if(!input) {
    cout << "Input file not opened" << endl;
    return -1;
  }

  ofstream output(argv[2]);
  //Output validity check
  if(!output) {
    cout << "Output file not opened" << endl;
    return -1;
  }

  //Reading Input
  int radius, xcenter, ycenter, height, width;
  input >> radius >> xcenter >> ycenter >> height >> width;


  //Creating the Circle
  Circle cir(radius, xcenter, ycenter);


  //Initializing vector of pixels
  vector< vector<Pixel> > pixVec;
  pixVec.resize(height, vector<Pixel>(width)); //<-Resize vector as needed


  //Fill vector pixels
  fillVec(pixVec, cir);

  //Print image using created vector
  printVec(output, pixVec, height, width);

  input.close();
  output.close();


return 0;
}
