#include "Person.h"
#include <string>
using namespace std;

Person::Person() {
  this->last = "";
  this->first = "";
  this->email = "";
  this->address = Address();
  this->bday = Date();
}

Person::Person(string a, string b, string c, int d, string e, string f,
 string g, int h, int i, int j, int k) {

  last = a;
  first = b;
  email = c;
  address = Address(d, e, f, g, h);
  bday = Date(i, j, k);
 }

Address Person::getAddress() {
  return this->address;
}

void Person::setPerson(string last, string first, string email, int house,
               string street, string city, string state, int zip,
               int month, int day, int year) {

  this->last = last;
  this->first = first;
  this->email = email;
  this->address = setAddress(house, street, city, state, zip);
  this->bday.month = setMonth(month);
  this->bday.day = setDay(day);
  this->bday.year = setYear(year);
}

void Person::printInfo(ofstream& out) {
  out << last << ", " << first << " " << email << endl;
  out << address.printAddress;
  out << bday.printDate;
}

int Person::getAge() {

}

Person::~Person() {
}
