#include <iostream>
#include "NumberArray2.h"
using namespace std;

//*****************************************
//Copy constructor allocates a new        *
//array and copies into it the entries    *
//of the array in the other object.       *
//*****************************************
NumberArray::NumberArray( const NumberArray &obj)
{
    //cout <<"inside Copy Constructor";
  int index;
  arraySize = obj.arraySize;
  aPtr = new double[arraySize];
  for(index = 0; index < arraySize; index++)
    aPtr[index] = obj.aPtr[index];
}

//*********************************************
//Constructor allocates an array of the       *
//given size and sets all its entries to the  *
//given value.                                *
//*********************************************
NumberArray::NumberArray(int size, double value)
{
  int index;
  arraySize = size;
  aPtr = new double[arraySize];
  for(index = 0; index < arraySize; index++)
     aPtr[index] = value;

}

//******************************************************
//Sets all the entries of the array to the same value. *
//******************************************************
void NumberArray::setValue(double value)
{
  int index;
  for(index = 0; index < arraySize; index++)
     aPtr[index] = value;
}

//**************************************
//Prints all the entries of the array. *
//**************************************
void NumberArray::print() const
{
  int index;
  for(index = 0; index < arraySize; index++)
    cout << aPtr[index] << "  ";
}

NumberArray::~NumberArray()
{
    if (arraySize > 0) delete [] aPtr;
}
