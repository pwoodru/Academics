#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main () {

  ifstream in("eof.txt");   // open file
  /*need to validate that the file opened.  */

  if(!in.is_open())
  {
      cout << "File failed to open"<< endl;
      exit(EXIT_FAILURE);
  }

  char c;
  /*This loops through the entire file reading one character
   *at a time then prints it out to the screen.*/
  while(!in.eof())
  {
     in.get(c);
     cout << c;
  }
  /*Now that we are done with the file close it*/
    in.close();

  return 0;
}
