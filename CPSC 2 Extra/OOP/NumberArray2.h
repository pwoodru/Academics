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
  ~NumberArray() 
  { cout >> "Destructor\n";
    if (arraySize > 0) delete [] aPtr; 
  }
  void print() const;
  void setValue(double value);
};