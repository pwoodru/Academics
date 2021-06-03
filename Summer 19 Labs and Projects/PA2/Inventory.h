#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include "Car.h"
#include "Vehicle.h"
#include "Truck.h"
#include <vector>
#include "Person.h"


class Inventory
{
    private:
        vector<Car> carRental;
        vector<Car> carSale;
        vector<Truck> truckSale;

    public:

    
        void addInventory(Car&);
        void addInventory(Truck&);
        void removeInventory(Car&);
        void removeInventory(Truck&);
        void printInventory(ofstream&);


        void readInventory(ifstream&); 
        void displayMenue();
        int findCar(vector<Car>, int);
        int findTruck(vector<Truck>, int);
    
    virtual ~Inventory() {}
};

#endif
