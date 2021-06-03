// This program demonstrates the bounds-checking
// capabilities of the IntArray class.
#include <iostream>
#include "intArray.h"
using namespace std;

int main()
{
    IntArray table(10);
        
    // Store values in the array
    for (int x = 0; x < table.size(); x++)
       table[x] = x;
		
    // Display the values in the array
    for (int x = 0; x < table.size(); x++)
       cout << table[x] << " ";
    cout << endl;
	
    cout << "Attempting to store outside the array bounds:\n";
    table[table.size()] = 0;
	
    return 0;
}