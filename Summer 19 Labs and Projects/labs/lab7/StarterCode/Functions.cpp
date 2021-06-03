#include "Functions.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<Person> readData(string argv[1]) {
  ifstream input;
  input.open(argv[1]);

  if (!input.is_open()) {
    cout << "Input did not open correctly." << endl;
    exit(1);
  }

  vector<Person> people;
  Person JohnDoe;
  string lastName;
  string firstName;
  string e;
  int home;
  string road;
  string city;
  string st;
  int z;
  int m;
  int d;
  int y;

  while(!input.eof) {
    input >> lastName >> firstName;
    input >> home >> road;
    input >> city >> st >> z;
    input >> e;
    input >> m >> d >> y;
    JohnDoe.setPerson(lastName, firstName, e, home, road, city, st, z, m, d, y);
    people.push_back(JohnDoe);
  }
return people;
}

void sortPerson(vector<Person> &person) {
  
}
