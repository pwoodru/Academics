#ifndef TRUCK_H
#define TRUCK_H
#include <iostream>
#include <fstream>
#include "Vehicle.h"


class Truck : public Vehicle
{
    private:
        string bedType;
    public:
        Truck();
        Truck(ifstream& in);
        void printInfo(ofstream&);
        void printInfo();
        virtual ~Truck() {}

};

#endif
