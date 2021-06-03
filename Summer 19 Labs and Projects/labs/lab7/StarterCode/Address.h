#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
using namespace std;

class Address
{
  private:
    int house;
    string street;
    string city;
    string state;
    int zip;

  public:
    Address(int, string, string, string, int);

    //setter
    void setAddress(int, string, string, string, int);

    void printAddress(ofstream&);

    virtual ~Address() {}
};

#endif
