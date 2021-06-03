#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    vector<double> d;
    cout << "Default-constructed capacity is " << v.capacity() << '\n';
    cout << "Size is: " << v.size() << endl;
    v.resize(100);
    cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
    cout << "Size is: " << v.size() << endl;
    v.clear();
    cout << "Capacity after clear() is " << v.capacity() << '\n';
    cout << "Size is: " << v.size() << endl;
    v.shrink_to_fit();
    cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    cout << "Size is: " << v.size() << endl;
    
    return 0;
}

/* Output:
 Default-constructed capacity is 0
 Size is: 0
 Capacity of a 100-element vector is 100
 Size is: 100
 Capacity after clear() is 100
 Size is: 0
 Capacity after shrink_to_fit() is 0
 Size is: 0
 */
