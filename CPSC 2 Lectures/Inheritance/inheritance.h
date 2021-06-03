#include <string>
using namespace std;

enum Discipline { ECE, BIO, CS};
enum Classification { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };
/*This is a base class*/
class Person
{
  private:
    string name;
  public:
    Person()
    {
      cout << "Person Default constructor is being called" << endl;

      name = "noname ";
    }

    Person(string pName)
    { cout << "param Person constructor is being called" << endl;

      name = pName;
    }

    void setName(string pName)
    {
      //cout << "SetName is being called " << endl;
      name = pName;
    }
    string getName() const
    { //cout << "getName is being called " << endl;
      return name;
    }
};

class Student: public Person
{
  private:
    Discipline major;
    Person *advisor;
  public:

    void setMajor(Discipline d)
    { cout << "setMajor is being called " <<  endl;
      major = d;
    }
    Discipline getMajor() const
    {cout << "getMajor is being called" << endl;
      return major;
    }
    void setAdvisor(Person *p)
    {cout << "setAdvisor is being called" << endl;
      advisor = p;
    }
    Person *getAdvisor() const
    {cout << "getAdvisor is bing called" << endl;
      return advisor;
    }
};

class Faculty: public Person
{
  private:
    Discipline department;
  public:

    Faculty()
    {
        cout << "In Faculty Default constructor\n";
    }
    void setDepartment(Discipline d)
    { //cout << "setDepartment has been called" << endl;
      department = d;
    }

    Discipline getDepartment( ) const
    { //cout << "\ngetDepartment has been called" << endl;
      return department;
    }
};
