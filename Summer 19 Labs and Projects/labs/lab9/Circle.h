#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdlib.h>
#include "Point.h"
using namespace std;


class Circle
{
    private:
      Point center;
      int radius;

    public:
      Circle();
      Circle(Point& p, int a);
      int hit(Point&);
      Point getCenter();

};



#endif
