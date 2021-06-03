#include <iostream>
#include "MyString.h"

using namespace std;

int main(int argc, char const *argv[]) {
  MyString detective("Hello");
  MyString hello = (detective + ",");

  detective = "Sherlock";
  detective = "Mr. " + detective;
  detective += " Holmes";
  cout << hello << " " << detective << endl;
  cout << "String length is: "
       << (hello + " " + detective).len()
       << endl;
  cout << "Is Sherlock same as Poirot ?" << endl;
  MyString sherlock("Sherlock");
  MyString poirot("Poirot");
  cout << "Name of " << sherlock << " starts with the letter " << sherlock[0] << " and ends with " << sherlock[sherlock.len()-1]<<"." << endl;
  cout << "Name of " << poirot << " starts with the letter " << poirot[0] <<" and ends with " << poirot[poirot.len()-1 <<"." << endl;
  bool isEqual = sherlock == poirot;
  cout << boolalpha;
  cout << isEqual << endl;
  cout << "Then Sherlock is different than Poirot ?" << endl;
  cout << boolalpha;
  bool notEqual = sherlock != poirot;
  cout << notEqual << endl;

  cout << "The result of comparing string " << sherlock << "and " << poirot << ": " << endl;
  cout << "\n Sherlock < Poirot yields  "<< boolalpha << (sherlock < poirot) << endl;
  cout << "\n Sherlock > Poirot yields  "<< boolalpha << (sherlock > poirot) << endl;
  cout << "\n Sherlock <= Poirot yields  "<< boolalpha << (sherlock <= poirot) << endl;
  cout << "\n Sherlock >= Poirot yields  "<< boolalpha << (sherlock >= poirot) << endl;

  MyString stringInput;
  cout << "Who Sherlock trusts the most : " << endl;
  cin >> stringInput;
  cout << "You entered " << stringInput << endl;

  // TO D0
  // create a MyString object with your name
  // and call substring operator () to create a substring of your name
  // from a starting location and length of your choice such as mystring(4,5)
  //print to terminal
  return 0;
}
