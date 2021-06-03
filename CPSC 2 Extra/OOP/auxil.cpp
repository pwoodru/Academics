#include "auxil.h"
#include "budget3.h"  

//***********************************************************
// Definition of member function addBudget                  *
// This function is declared a friend by the Budget class   *
// It adds the value of argument b to the static corpBudget *
// member variable of the Budget class.                     *
//***********************************************************

void Aux::addBudget(double b)
{
    auxBudget += b;
    /*corpBudget is a static variable of the Budget class.  But since 
     *addBudget is a friend function of the Budget class it has access to the 
     *private variables (data).  But since we are in the Aux class Mr. Compiler
     *needs to know this belongs to the budget class. Hence the :: operator is
     *used.*/
    Budget::corpBudget += auxBudget;
}
Aux::Aux() 
{ 
    auxBudget = 0; 
}
   
double Aux::getDivBudget() const 
{ 
    return auxBudget; 
}