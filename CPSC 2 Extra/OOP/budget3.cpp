#include "budget3.h" 

// Definition of static member
double Budget::corpBudget = 0; 

//**********************************************************
// Definition of static member function mainOffice         *
// This function adds the main office's budget request to  *
// the corpBudget variable.                                *
//**********************************************************
void Budget::mainOffice(double budReq)
{
    corpBudget += budReq;
}

Budget::Budget() 
{ 
    divBudget = 0; 
}
void Budget::addBudget(double b)
{ 
    divBudget += b; 
    corpBudget += divBudget; 
}
    
double Budget::getDivBudget() const 
{ 
    return divBudget; 
}
    
double Budget::getCorpBudget() 
{ 
    return corpBudget; 
}