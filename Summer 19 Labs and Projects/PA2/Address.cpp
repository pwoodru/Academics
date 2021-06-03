#include "Address.h"

using namespace std;

Address::Address() {
  house = 0;
  street = " ";
  city  = " ";
  state = " ";
  zip = 0;
}

Address::Address(int a, string b, string c, string d, int e) {
  this->house = a;
  this->street = b;
  this->city = c;
  this->state = d;
  this->zip = e;
}

void Address::setAddress(int a, string b, string c, string d, int e) {
  this->house = a;
  this->street = b;
  this->city = c;
  this->state = d;
  this->zip = e;
}

void Address::printAddress(ofstream& out) {
  out << house << " " << street << " " << city
  << ", " << state << " " << zip << endl;
}

Address::~Address() {
}
