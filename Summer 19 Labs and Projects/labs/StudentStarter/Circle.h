#ifndef CIRCLE_H
#define CIRCLE_H
#include <stdlib.h>
#include "Point.h"


class Circle
{
    private:
      Point center;
      int radius;

    public:
      Circle();
      Circle(Point&, int);
      int hit(Point&);
      Point getCenter();

};



#endif
