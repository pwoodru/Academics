#include<iostream>
using namespace std;

class Weird
{
    private:
        int value;

    public:
        Weird(int v)
        {
            value = v;
        }

        void operator=(const Weird& right)
        {
            cout << "This is the way I want my = to work." << endl;
            cout << "When I use the = it should simply print the value of the";
            cout << " object being passed in\n";
            cout << right.value << endl;
        }
};


int main()
{
    /*What should print here*/
    Weird a(5), b(10);
    a = b; 

    return 0;

}