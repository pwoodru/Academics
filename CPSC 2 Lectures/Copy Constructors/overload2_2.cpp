#include "overload2_2.h"


//***************************************************
//The overloaded operator function for assignment   *
//***************************************************
NumberArray& NumberArray::operator=(const NumberArray &right)
{  //cout<< "In operator =" << endl;
  if (arraySize > 0)  delete [] aPtr;
  arraySize = right.arraySize;
  aPtr = new double[arraySize];

  for (int index = 0; index < arraySize; index++)
   aPtr[index] = right.aPtr[index];
  return *this;
}

//*******************************************
//Copy Constructor                          *
//*******************************************
NumberArray::NumberArray(const NumberArray &obj)
{ //cout << "In copy constructor" << endl;
  arraySize = obj.arraySize;
  aPtr = new double[arraySize];

  for(int index = 0; index < arraySize; index++)
    aPtr[index] = obj.aPtr[index];
}

//*********************************************
//Constructor                                 *
//*********************************************
NumberArray::NumberArray(int size, double value)
{  //cout << "in regular constructor" << endl;
  arraySize = size;
  aPtr = new double[arraySize];
  //setValue(value);
  for(int index = 0; index < arraySize; index++)
     aPtr[index] = value;
}

//***************************************************
//Sets the value stored in all entries of the array *
//***************************************************
void NumberArray::setValue(double value)
{
  for(int index = 0; index < arraySize; index++)
     aPtr[index] = value;
}

//***************************************
//Print out all entries in the array    *
//***************************************
void NumberArray::print()
{
  for(int index = 0; index < arraySize; index++)
    cout << aPtr[index] << "  ";
}
