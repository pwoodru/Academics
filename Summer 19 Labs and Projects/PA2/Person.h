#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "Date.h"
#include <ctime>
#include <string>

class Person
{
  private:
    string last;
    string first;
    string email;
    long long phone;
    Address address;
    Date bday;

  public:
    Person();
    Person(string, string, string, long long int);
    Person(string, string, string, int, string, string, string, int,
      int, int, int);
    Person(string, string, string, int, int, int);

    Address getAddress();
    void setPerson(string last, string first, string email, int house,
                   string street, string city, string state, int zip,
                   int month, int day, int year);
    //Date getDate();

    int getAge();
    void printInfo(ofstream&);
    virtual ~Person() {}
};

#endif
