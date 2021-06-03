#include <vector>
#include <iostream>
using namespace std;


int main()
{
  /*Traversing through a vector using standard for loop*/
  vector<int> myIntVector;
  // Add some elements to myIntVector
  myIntVector.push_back(1);
  myIntVector.push_back(4);
  myIntVector.push_back(8);

  for(int y = 0; y < myIntVector.size(); y++)
  {
      cout<<myIntVector[y]<<" ";
  }
  cout << endl;

  /*creating an iterator*/
  vector<int>::iterator myIterator;
  /*Traversing through a vector using iterators and a for loop*/

  /*I set the iterator to the begining of the vector and I traverse through the
   *vector until I reach the end*/
  for(myIterator = myIntVector.begin();
      myIterator != myIntVector.end(); myIterator++)
  {
    /*An iterator is a pointer so if I want the value I must dereference the
     *pointer*/
    cout << *myIterator << " ";
  }
  cout << endl;

  return 0;
}
