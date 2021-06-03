#include "Address.h"
#include <string>
using namespace std;

Address::Address(int h, string str, string c, string st, int z) {
  this->house = h;
  this->street = str;
  this->city = c;
  this->state = st;
  this->zip = z;
}

void Address::setAddress(int h, string str, string c, string st, int z) {
  house = h;
  street = str;
  city = c;
  state = st;
  zip = z;
}

void Address::printAddress(ofstream& out) {
  out << house << " " << street << " " << city
  << ", " << state << " " << zip << endl;
}
