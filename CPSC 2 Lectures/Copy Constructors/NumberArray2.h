#include <iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;
public:
  NumberArray(const NumberArray &);
  NumberArray(int size, double value);
  ~NumberArray();
  void print() const;
  void setValue(double value);
};
