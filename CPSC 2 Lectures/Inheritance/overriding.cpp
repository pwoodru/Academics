/*Overriding example*/
#include <iostream>
#include <string>
using namespace std;

class Base
{
  private:
    string name;
  public:
    Base() :name("noName")
    {

    }

    Base(string n) : name(n)
    {

    }

    void setName(string name)
    {
      this->name = name;
    }
    string getName()
    {
      return name;
    }

    void printInfo()
    {
      cout << name << endl;
    }

};

class Derived : public Base
{
  private:
     string title;
     string address;
     string city;
     string state;
     int zip;

  public:
    void printName()
    {
      cout << title << " " << getName() << endl;
      cout << address << endl << city << "," << zip << endl;
    }

    Derived(): Base("Frankenstein"), title("Dr."), address("123 Main St."), city("Clemson"),
               state("SC"), zip(29634) { }

    Derived(string title, string name, string address, string city,
      string state, int zip):
      title(title), Base(name),  address(address), city(city),
      state(state), zip(zip){ }


    void setAddress(string address)
    {
      this->address = address;
    }
    void setTitle(string title)
    {
      this->title = title;
    }
    void setCity(string city)
    {
      this->city = city;
    }
    void setState(string state)
    {
      this->state = state;
    }
    void setZip(int zip)
    {
      this->zip = zip;
    }
    void printInfo()
    {
      cout << title << " " << getName() << endl;
      cout << address << endl;
      cout << city << ", " << state << " " << zip << endl;
      cout << endl;
    }
};


int main()
{
    Base base;
    base.printInfo();
    base.setName("Yvon Feaster");

    base.printInfo();

    Derived derived;
    derived.printInfo();
    derived.setName("Yvon H. Feaster");

    Derived derived2("Dr.", "Yvon", "301 McAdams Hall", "Clemson", "SC", 29634);
    derived2.printInfo();

    return 0;
}
