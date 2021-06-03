#include <iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;
public:
  NumberArray(int size, double value);
 
  void print() const;
  void setValue(double value);
};
