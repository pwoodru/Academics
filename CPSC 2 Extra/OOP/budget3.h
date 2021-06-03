#ifndef BUDGET3_H 
#define BUDGET3_H
#include "auxil.h"	// For Aux class declaration

// Budget class declaration
class Budget
{
private:
    static double corpBudget;
    double divBudget;
public:
    Budget(); 
    void addBudget(double b);
    double getDivBudget() const;
    static double getCorpBudget();
    static void mainOffice(double);
    friend void Aux::addBudget(double);
};
#endif