#include <iostream>
using namespace std;

class NumberArray
{
private:
  double *aPtr;
  int arraySize;
public:
  // Copy assignment and copy constructor
  NumberArray& operator=(const NumberArray &right);    
  NumberArray(const NumberArray &);
  
  // Other constructor and Destructor
  NumberArray(int size, double value);
  ~NumberArray();
  
  
  void print() const;
  void setValue(double value);
};
