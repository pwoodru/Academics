#include <string>
using namespace std;

enum Discipline { ARCHEOLOGY, BIOLOGY, COMPUTER_SCIENCE };
enum Classification { FRESHMAN, SOPHOMORE, JUNIOR, SENIOR };

class Person
{
//protected:
private:
  string name;
public:
  Person() { setName(""); }
  Person(string pName) { setName(pName); }
  void setName(string pName) { name = pName; }
  string getName() const { return name; }
};

class Student:public Person
{
private:
  Discipline major;
  Person *advisor;
public:

  Student(string sname, Discipline d, Person *adv)
  : Person(sname)
  {
    major = d;
    advisor = adv;
  }
  void setMajor(Discipline d) { major = d; }
  Discipline getMajor() const { return major; }
  void setAdvisor(Person *p) { advisor = p; }
  Person *getAdvisor() const { return advisor; }
};

class Faculty:public Person
{
private:
  Discipline department;
public:
  Faculty(string fname, Discipline d) : Person(fname)
  {
     department = d;
  }
  void setDepartment(Discipline d) { department = d; }
  Discipline getDepartment( ) const { return department; }
};

class TFaculty : public Faculty
{
private:
  string title;
public:
  TFaculty(string fname, Discipline d, string title)
  : Faculty(fname, d)
  {
    setTitle(title);
  }
  void setTitle(string title) { this->title = title; }

  // Override getName()
  string getName( ) const
  {
    /*If your data is protected then you have direct access to name
     *however if the data is private then you must call the getter
     *since you inheritate from Person you can call getName using the
     *Person scope operator*/
      //return title + " " + name;
	   return title + " " + Person::getName();
  }
};
