/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "image.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

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

  Header headerF;
  headerF = headerF.read_header(input);
  vector<vector<Pixel> > vec;
  vec.resize(800, vector<Pixel>(600));

  Image image;
  image = image.read_pixels(input, headerF, vec);
  image.write_p6(output, image);

return 0;
}
