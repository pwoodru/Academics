#include "Functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math>
using namespace std;

void fillColor(vector< vector<Pixel> >& vec2D) {
  unsigned int a, b;
  for (a = 0; a < vec2D.size(); a++) {
    for (b = 0; b < vec2D[a].size(); b++) {
        vec2D.at(a).at(b).r = 246;
        vec2D.at(a).at(b).g = 102;
        vec2D.at(a).at(b).b = 51;
    }
  }
}

void fillCircle(vector< vector<Pixel> >& vec2D, Circle& cir) {
  unsigned int a, b;
  int plot;

  for (a = 0; a < vec2D.size(); a++) {
    for (b = 0; b < vec2D[a].size(); b++) {
      Point p;
      p.setX(b);
      p.setY(a);
      plot = cir.hit(p);

      //If test point is within circle
      if (plot == 1) {
        vec2D.at(a).at(b).r = 82;
        vec2D.at(a).at(b).g = 45;
        vec2D.at(a).at(b).b = 128;

      }
      //If test point is not within circle
      else {
        vec2D.at(a).at(b).r = 246;
        vec2D.at(a).at(b).g = 102;
        vec2D.at(a).at(b).b = 51;

      }
    }
  }
}

void printVec(ofstream& output, vector< vector<Pixel> >&vec, int row, int col) {
  //Print header to file first
  output << "P6" << endl << col << " " << row << " " << "255" << endl;

  //Print pixels from inside vector
  unsigned int i, j;
  for (i = 0; i < vec.size(); i++) {
    for (j = 0; j < vec[i].size(); j++) {
      output << vec.at(i).at(j).r;
      output << vec.at(i).at(j).g;
      output << vec.at(i).at(j).b;
    }
  }
}
