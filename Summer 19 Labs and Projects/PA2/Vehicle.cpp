#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle() {
  this->type = " ";
  this->make = " ";
  this->model = " ";
  this->year = 0;
  this->color = " ";
  this->salesPrice = 0;
  this->miles = 0;
  this->condition = " ";
  this->id = 0;
  //this->inventoryCount = 0;
}

Vehicle::Vehicle(ifstream& in) {
  in >> type >> make >> model >> year >> color
  >> salesPrice >> miles >> condition;
  this->id = 0;
  inventoryCount++;
}

int Vehicle::getYear() {
  return this->year;
}

int Vehicle::getMiles() {
  return this->miles;
}

string Vehicle::getCondition() {
  return this->condition;
}

int Vehicle::getCount() {

}

int Vehicle::getID() {
  return this->id;
}

void Vehicle::setRent() {

}

void Vehicle::addInventory() {

}

void Vehicle::printInfo() {

}

void Vehicle::printInfo(ofstream& out) {

}

Vehicle::~Vehicle() {
}
