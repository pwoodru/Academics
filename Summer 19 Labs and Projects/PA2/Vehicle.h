#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Vehicle
{
    private:
        string type;
        string make;
        string model;
        int year;
        string color;
        double salesPrice;
        int miles;
        string condition;
        int id;
        static int inventoryCount;
  

    public:


        Vehicle();
        Vehicle(ifstream&);
        virtual ~Vehicle();
        void printInfo(ofstream&);
        void printInfo();
        int getYear();
        int getMiles();
        string getCondition();
        void addInventory();
        int getCount();
        void setRent();
        int getID();
    


};

#endif
