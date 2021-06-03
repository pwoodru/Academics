#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
  private:
    int month;
    int day;
    int year;


  public:
    Date();
    Date(int, int, int);

    void setMonth(int);
    void setDay(int);
    void setYear(int);

    int getMonth();
    int getDay();
    int getYear();

    void printDate(ofstream&);

};
#endif
