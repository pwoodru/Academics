#ifndef CAR_H
#define CAR_H
#include <fstream>
#include <iostream>
#include "Vehicle.h"


/*The car class will represent the car.  The Body style will be available. The
 *user will be able to sort by the body style*/
class Car : public Vehicle
{
    private:
        bool rentable;
        bool available;

    public:
        Car();
        Car(ifstream&);
        /*This function determines if the car inventory could be a rental
         *must be < 2 years old, in Excellent condition, mileage < 450000*/
        void isRentable();
        void printInfo(ofstream& out);
        void printInfo();
        int getCurrentYear();
        bool getRentable();
    virtual ~Car() { }
};

#endif
