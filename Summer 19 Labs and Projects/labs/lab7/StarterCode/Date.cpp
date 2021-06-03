#include "Date.h"
#include <iostream>
using namespace std;


//Default Constructor
Date::Date() {
  this->month = 0;
  this->day = 0;
  this->year = 0;
}

//Regular Constructor
Date::Date(int a, int b, int c) {
  month = a;
  day = b;
  year = c;
}

//Setters for month, day, year
void Date::setMonth(int a) {
  this->month = a;
}

void Date::setDay(int a) {
  this->day = a;
}

void Date::setYear(int a) {
  this->year = a;
}

//Getters for month, day, year
int Date::getMonth() {
  return this->month;
}

int Date::getDay() {
  return this->day;
}

int Date::getYear() {
  return this->year;
}

//Print info
void Date::printDate(ofstream& out) {
  out << month << " " << day << ", " << year << endl;
}
