/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#include "shape.h"
#include "image.h"
#include "circle.h"
#include "triangle.h"
#include "quadrilateral.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

  //Input file
  ifstream input(argv[1]);
  //Input validity check
  if(!input) {
    cout << "Input file not opened" << endl;
    return -1;
  }

  //Output file
  ofstream output(argv[2]);
  //Output validity check
  if(!output) {
    cout << "Output file not opened" << endl;
    return -1;
  }

  //Vector containing pixels for final image, will be used at the end
  vector<vector<Pixel> > pixFinal;
  pixFinal.resize(500, vector<Pixel>(500));

//Looping variable
int i;
for (i = 0; i < 3; i++) {
  //Program starts by reading name of shapes
  cout << "Reading shapes..." << endl;
  string tempName;
  input >> tempName;

  //Shape names for comparison
  string circlename = "Circle";
  string trianglename = "Triangle";
  string quadname = "Quadrilateral";

  //Depending on shape name, creates instances of that shape
  if (tempName == circlename) {
    //Circle creation and information reading
    cout << "Shape is a circle! Creating now..." << endl;

    //Polymorphism start????
    Shape *circleshape;
    Circle cir;
    circleshape = &cir;

    circleshape->readInfo(input);
    //Using the information read into the circle, set the point
    cout << "Setting points..." << endl;
    circleshape->setPoint(circleshape->getPoints());

    //Create a 2D vector of pixels
    vector<vector<Pixel> > pixCir;
    //Resize vector to the standard 500x500 for this project
    pixCir.resize(500, vector<Pixel>(500));

    cout << "Filling vectors..." << endl;
    //Fill vector with pixels
    //cir.fillVec(pixCir, cir);             //FLAG

    cout << "Creating image..." << endl;
    //Create header for image
    int htc, wdc, mvc;
    htc = 500; wdc = 500; mvc = 255;
    Header headerC(htc, wdc, mvc);

    //Create image by setting vectors equal
    Image imageCir(pixCir, headerC);

    //Fill vector with pixels using draw
    circleshape->draw(imageCir, input);

    //Overwrite pixFinal pixels for circle shape
    for (int a = 0; a < 500; a++) {
    for (int b = 0; b < 500; b++) {
    pixFinal.at(a).at(b).set_red(imageCir.getPixel().at(a).at(b).get_red());
    pixFinal.at(a).at(b).set_green(imageCir.getPixel().at(a).at(b).get_green());
    pixFinal.at(a).at(b).set_blue(imageCir.getPixel().at(a).at(b).get_blue());
      }
    }
    //Set created image to the image pointer outside of the loop
    //for later use
    //circleimg = &imageCir;
    cout << "Done! Circle printed." << endl << endl;
  }
  else if (tempName == trianglename) {
    //Triangle creation and information reading
    cout << "Shape is a triangle! Creating now..." << endl;

    //Polymorphism???
    Shape *triangleshape;
    Triangle tri;
    triangleshape = &tri;

    triangleshape->readInfo(input);

    //Using the information read into the triangle, set the point
    cout << "Setting Points..." << endl;
    triangleshape->setPoint(triangleshape->getPoints());

    //Create a 2D vector of pixels
    vector<vector<Pixel> > pixTri;
    //Resize vector to the standard 500x500 for this project
    pixTri.resize(500, vector<Pixel>(500));

    cout << "Filling vectors..." << endl;
    //Fill vector with pixels

    cout << "Creating image..." << endl;
    //Create header for image
    int htt, wdt, mvt;
    htt = 500; wdt = 500; mvt = 255;
    Header headerT(htt, wdt, mvt);

    //Create image by setting vectors equal
    Image imageTri(pixTri, headerT);

    //Fill vector with pixels using draw
    triangleshape->draw(imageTri, input);

    //Overwrite pixFinal pixels for Triangle shape
    for (int a = 0; a < 500; a++) {
    for (int b = 0; b < 500; b++) {
    if ((int)imageTri.getPixel().at(a).at(b).get_red() == 255) {
    pixFinal.at(a).at(b).set_red(imageTri.getPixel().at(a).at(b).get_red());
    pixFinal.at(a).at(b).set_green(imageTri.getPixel().at(a).at(b).get_green());
    pixFinal.at(a).at(b).set_blue(imageTri.getPixel().at(a).at(b).get_blue());
    }
    }
    }
    cout << "Done! Triangle printed." << endl << endl;
  }
  else if (tempName == quadname) {
    //Quadrilateral creation and information reading
    cout << "Shape is a quadrilateral! Creating now..." << endl;

    //Polymorphism
    Shape *quadshape;
    Quadrilateral quad;
    quadshape = &quad;

    //Read info, calling quad's readInfo function
    quadshape->readInfo(input);

    //Using the information read into the triangle, set the point
    cout << "Setting Points..." << endl;
    quadshape->setPoint(quadshape->getPoints());

    //Create a 2D vector of pixels
    vector<vector<Pixel> > pixQuad;
    //Resize vector to the standard 500x500 for this project
    pixQuad.resize(500, vector<Pixel>(500));

    cout << "Filling vectors..." << endl;
    //Fill vector with pixels

    cout << "Creating image..." << endl;
    //Create header for image
    int htq, wdq, mvq;
    htq = 500; wdq = 500; mvq = 255;
    Header headerQ(htq, wdq, mvq);

    //Create image by setting vectors equal
    Image imageQuad(pixQuad, headerQ);

    //Fill vector with pixels using draw
    quadshape->draw(imageQuad, input);

    //Overwrite pixFinal pixels for Quad shape
    for (int a = 0; a < 500; a++) {
    for (int b = 0; b < 500; b++) {
    if ((int)imageQuad.getPixel().at(a).at(b).get_green() == 255) {
    pixFinal.at(a).at(b).set_red(imageQuad.getPixel().at(a).at(b).get_red());
    pixFinal.at(a).at(b).set_green(imageQuad.getPixel().at(a).at(b).get_green());
    pixFinal.at(a).at(b).set_blue(imageQuad.getPixel().at(a).at(b).get_blue());
    }
    }
    }
    cout << "Done! Quadrilateral printed." << endl << endl;
  }
}

  cout << "Merging pixels... done!" << endl << endl;
  //Now that all three shapes are created, send the image to output
  int htf, wdf, mvf;
  htf = 500; wdf = 500; mvf = 255;
  Header headerF(htf, wdf, mvf);

  cout << "Enjoy your image of Kermit the Frog!" << endl << endl;

  Image Kermit(pixFinal, headerF);
  Kermit.write_img(output, Kermit);
return 0;
}
