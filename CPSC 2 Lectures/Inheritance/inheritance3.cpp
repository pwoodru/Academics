#include "inheritance3.h" 
//*********************************************
// Constructor for the Student class.         *
//*********************************************
Student::Student(string sname, Discipline d, Person *adv)
: Person(sname)
{ 
  major = d;
  advisor = adv;
}