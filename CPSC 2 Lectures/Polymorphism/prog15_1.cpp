// This program demonstrates type compatibility within
// an inheritance hierarchy.
#include "inheritance4.h"
#include <iostream>
using namespace std;

int main()
{
   /*What is the hierarchy here:  Person<-Faculty<-TFaculty*/
   Person *pp;
   Faculty *pf;
   TFaculty *ptf;
   ptf = new TFaculty("Indiana Jones", ARCHEOLOGY, "Dr.");

   // Calling getName through a pointer to TFaculty uses
   // the version of getName in TFaculty
   cout << "Get name through a pointer to TFaculty: ";
   cout << ptf->getName() << endl;

   // Assignment of derived to base needs no cast
   pf = ptf;

   // Calling getName through a pointer to Faculty uses the
   // version of getName in Faculty
   cout << "Get name through a pointer to Faculty: ";
   cout << pf->getName() << endl;

   // Assignment of derived to base needs no cast
   pp = ptf;
   /*This will use the getname from the Person class. Remember Person is
    *the base class and it is not aware of the members of the derived class
    *if you want to call the getname from the derived class TFaculty you
    *must tell the compiler to treat the variable as if it were of type TFaculty
    *This is done by type casting*/
   cout << pp->getName() << endl;

   // Derived class members can be accessed using a cast
   cout << "Get name through a cast to pointer to TFaculty: ";
   /*This tells the compiler, hey I know you think I am a Person
    *but I want you to treat me like a TFaculty and call TFaculty's
    *getName function.*/
   cout << static_cast<TFaculty *>(pp)->getName() << endl;

   /*Another way to tell the compiler to use the TFaculty class members is to
    *create an instance of the TFaculty.  Set it equal to an instance of Person that
    *has been typecast to TFaculty, as shown below.  */

   // Assigment from base to derived needs a cast
   TFaculty *ptf1;
   ptf1 = static_cast<TFaculty *>(pp);

   // Access getName through a pointer to TFaculty
   cout << "Get name through a pointer to TFaculty: ";
   cout << ptf1->getName() << endl;

   return 0;
}
