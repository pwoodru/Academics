//This is used by the multi-assign program. It is not
//listed in the book.
#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H
#include <iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;
public:
  NumberArray& operator=(const NumberArray &right); //overloaded operator function
  NumberArray(const NumberArray &);
  NumberArray(int size, double value);
  ~NumberArray() { if (arraySize > 0) delete [] aPtr; }
  void print();
  void setValue(double value);
};

#endif
