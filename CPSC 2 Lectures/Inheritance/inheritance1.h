#include <iostream>
#include <string>
using namespace std;

enum Discipline { ECE, BIO, CS };
enum Classification { Freshman, Sophomore, Junior, Senior };

class Person
{
protected:
  string name;
public:
  Person()
  {
    cout << "Inside person default constructor\n";
     name = " ";
  }
  Person(string pName)
  { cout << "Inside person regular constructor\n";
     name = pName;
  }
  void setName(string pName) { name = pName; }
  string getName() const { return name; }
};

class Student:public Person
{
protected:
  Discipline major;
  Person *advisor;
public:
  // Constructor
  Student(string sname, Discipline d, Person *adv);

  void setMajor(Discipline d) { major = d; }
  Discipline getMajor() const {return major; }
  void setAdvisor(Person *p){advisor = p;}
  Person *getAdvisor() const { return advisor; }
};

class Faculty:public Person
{
private:
  Discipline department;
public:
  // Constructor
  Faculty(string fname, Discipline d)//: Person(fname), department(d)
  {
    cout << "inside Faculty constructor\n";
     // Access the protected base class member
     name = fname;
     department = d;
  }
  // Other member functions
  void setDepartment(Discipline d) { department = d; }
  Discipline getDepartment( ) const{ return department; }
};
