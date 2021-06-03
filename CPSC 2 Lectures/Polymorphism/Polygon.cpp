// pointers to base class
#include <iostream>
using namespace std;

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
};

class Rectangle: public Polygon {
  public:
    int area()
      { return width*height; }
};

class Triangle: public Polygon {
  public:
    int area()
      { return width*height/2; }
};

int main () {
  Rectangle rect;
  Triangle trgl;
  Polygon * ppoly1 = &rect;
  Polygon * ppoly2 = &trgl;
  /*The base class is the only one that has a set_values function so the base
   *class function gets called*/
  ppoly1->set_values (4,5);
  ppoly2->set_values (4,5);
  /*Can ppoly1 and ppoly2 */
  cout << rect.area() << '\n';
  cout << trgl.area() << '\n';
  return 0;

  }
