#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Person.h"

/*This function is responsible for reading in the data from the input file.
 *The data will consist of the name, address, email and Birthday of a person
 *You are to store the information for each person in a vector of type person.
 *Parameters:
 *string - this represents the file name that is given through command line
 *arguments.
 *Return:
 *vector of type Person */
vector<Person> readData(string);
void sortPerson(vector<Person> &person);
#endif
