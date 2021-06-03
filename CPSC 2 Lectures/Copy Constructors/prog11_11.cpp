// This program demonstrates the Length class's overloaded
// prefix ++, postfix ++, and stream operators.
#include <iostream>
#include "Length1.h"
using namespace std;

int main()
{
    Length first(0), second(1, 9), c(0);

    Length first1(0), second1(0), third1(0);
    int f, i;
    cout << "Enter a distance in feet and inches: ";
    cin  >> f >> i;
    first1.setLength(f, i);
    cout << "Enter another distance in feet and inches: ";
    cin  >> f >> i;
    second1.setLength(f, i);

    // Test the + and - operators
    third1 = first1 + second1;
    cout << "first1 + second1 = ";
    cout << third1.getFeet() << " feet, ";
    cout << third1.getInches() << " inches.\n";
    third1 = first1 - second1;
    cout << "first1 - second1 = ";
    cout << third1.getFeet() << " feet, ";
    cout << third1.getInches() << " inches.\n";

    // Test the relational operators
    cout << "first == second = ";
    if (first1 == second1) cout << "true"; else cout << "false";
    cout << "\n";
    cout << "first1 < second1 = ";
    if (first1 < second1) cout << "true"; else cout << "false";
    cout << "\n";


    /*Remember ++second increments second before it assigns the value to first*/
    cout << "Demonstrating prefix ++ operator and output operator.\n";
    for (int count = 0; count < 4; count++)
    {
        first = ++second;
        cout << "First: " << first <<  ". Second: " << second << ".\n";
    }

    /*Remember second++ assigns the value of second to first then increments*/
    cout << "\nDemonstrating postfix ++ operator and output operator.\n";
    for (int count = 0; count < 4; count++)
    {
        first = second++;
        cout << "First: " << first <<  ". Second: " << second << ".\n";
    }

    cout << "\nDemonstrating input and output operators.\n";
    cin >> c;
    cout << "You entered " << c << "." << endl;
    return 0;
}
