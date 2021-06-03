#include <iostream>
#include "overload2.h"
using namespace std;


NumberArray NumberArray::operator(const NumberArray &right)
{
  cout << "In = operator";
  if (arraySize > 0) delete [] aPtr;
  arraySize = right.arraySize;
  aPtr = new double[arraySize];
  for (int index = 0; index < arraySize; index++)
    aPtr[index] = right.aPtr[index];
  return *this;
}
