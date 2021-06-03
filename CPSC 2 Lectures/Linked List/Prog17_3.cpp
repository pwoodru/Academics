// This program demonstrates the add and
// display linked list operations.

#include "NumberList.h"
using namespace std;

int main()
{
    /*Creating an instance of the numberlist to use to call the functions.*/
    NumberList list;
    list.add(2.5);
    list.add(7.9);
    list.add(12.6);
    list.displayList();
    cout << endl;
    list.remove(7.9);
    list.displayList();
    cout << endl;
    return 0;
}
