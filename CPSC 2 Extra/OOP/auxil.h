#ifndef AUXIL_H 
#define AUXIL_H

// Aux class declaration.
class Aux 
{
private:
   double auxBudget;
public:
   Aux();
   void addBudget(double);
   double getDivBudget() const;
};
#endif