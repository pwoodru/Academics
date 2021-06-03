#include <iostream>
#include "NumberArray2.h"
using namespace std;





NumberArray::NumberArray( const NumberArray &obj );
{
    //cout << "Inside Copy Constructor"
  int index;
  arraySize = obj.arraySize;
  aPtr = new double[arraySize];
  for(index = 0; index < arraySize; index++)
    aPtr[index] = obj.aPtr[index];
}
