#include <iostream>
#include "overload.h" 
using namespace std;

//***************************************************
//The overloaded operator function for assignment.  *
//***************************************************
NumberArray& NumberArray::operator=(const NumberArray &right)
{cout << "Assignment operator\n";
  /*If the the address of the object on the left of the = is the same object on
   *the right then we don't need to do anything.  And yes this could very well 
   *happen. */
    if (this != &right)
    {
      /*Now we need to give the memory that the object on the left is pointing
       *to back to the OS (assuming is pointing to something)*/
      if (arraySize > 0) 
      { 
          delete [] aPtr; 
      }
      /*The first thing you need to do is set the array size of the lhs object
       *to the value of the rhs' object*/
      arraySize = right.arraySize;
      /*Create new memory for the lhs' object and then copy the values from the
       *rhs'object to the left hand side's object.*/
      aPtr = new double[arraySize];
      for (int index = 0; index < arraySize; index++)
      {
        aPtr[index] = right.aPtr[index];
      }
    }
    /*Here is one of those times I mentioned that you would need to the "this"
     *pointer. Notice that the = operator has a return value of NumberArray. 
     *Once we have completed the copying of the object, we will dereference the
     *explicit this pointer and return it. */
    return *this;
}

//**********************************************
//Copy constructor.                            *
//**********************************************
NumberArray::NumberArray(const NumberArray &obj)
{cout << "copy constructor\n";
  arraySize = obj.arraySize;
  aPtr = new double[arraySize];
  for(int index = 0; index < arraySize; index++)
  {
    aPtr[index] = obj.aPtr[index];
  }
}

//**********************************************
//Constructor.                                 *
//**********************************************
NumberArray::NumberArray(int size1, double value)
{cout << "Regular constructor\n";
  arraySize = size1;
  aPtr = new double[arraySize];
  setValue(value);
}

//****************************************************
//Sets the value stored in all entries of the array. *
//****************************************************
void NumberArray::setValue(double value)
{
  for(int index = 0; index < arraySize; index++)
  {
     aPtr[index] = value;
  }
}

//***************************************
//Print out all entries in the array.   *
//***************************************
void NumberArray::print() const
{
  for(int index = 0; index < arraySize; index++)
  {
    cout << aPtr[index] << "  ";
  }
}


NumberArray::~NumberArray() 
{cout<< "Destructor\n";
   if (arraySize > 0) delete [ ] aPtr; 
}