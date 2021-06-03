/***********************
Patrick Woodrum
CpSc 1020 Section 2, F18
pwoodru@clemson.edu
************************/

#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
#include "color.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace std;

class Shape
{
    //protected means derived classes have direct access to the data members
    protected:
        Color c;
        string name;
        vector <Point> pts;

    public:
        Shape();
        virtual void readInfo(ifstream& input) = 0;
        virtual void setPoint(vector <Point>) = 0;
        virtual bool isHit(Point&) = 0;
        virtual void draw(Image&, ifstream&) = 0;
        vector<Point> getPoints()const {return pts;}
        void setName(string Newname);
        string getName() const;
        void setColor(ifstream& input);
};

#endif
