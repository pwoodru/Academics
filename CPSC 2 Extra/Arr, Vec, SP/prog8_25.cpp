// This program demonstrates the vector size, 
// push_back, and pop_back member functions.
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> values;

	// Store values in the vector
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);
	cout << "The size of values is " << values.size() << " " << values.capacity() <<  endl;

	// Remove a value from the vector
	cout << "Popping a value from the vector...\n";
	values.pop_back();
	cout << "The size of values is now " << values.size() << " " << values.capacity() <<  endl;

	// Now remove another value from the vector
	cout << "Popping a value from the vector...\n";
	values.pop_back();
	cout << "The size of values is now " << values.size() << " " << values.capacity() << endl;

	// Remove the last value from the vector
	cout << "Popping a value from the vector...\n";
	values.pop_back();
	cout << "The size of values is now " << values.size() << " " << values.capacity() <<  endl;
	return 0;
}
