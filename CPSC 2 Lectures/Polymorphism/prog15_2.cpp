// This exhibits the default non-polymorphic behavior of C++.
#include "inheritance4.h"
#include <iostream>
using namespace std;

int main()
{
   //Create an array of pointers to Person objects (person is the declared type)
   const int NUM_PEOPLE = 5;
   Person *arr[NUM_PEOPLE] =
    {
      new TFaculty("Indiana Jones", ARCHEOLOGY, "Dr."),
      new Student("Thomas Cruise", COMPUTER_SCIENCE, NULL),
      new Faculty("James Stock", BIOLOGY),
      new TFaculty("Sharon Rock", BIOLOGY, "Professor"),
      new TFaculty("Nicole Eweman", ARCHEOLOGY, "Dr.")
    };
   // Print the names of the Person objects
   /*Person is the declared type*/
   for (int k = 0; k < NUM_PEOPLE; k++)
   {
      cout << arr[k]->getName() << endl;
   }
   return 0;
}
