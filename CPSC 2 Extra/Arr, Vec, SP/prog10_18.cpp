// This program illustrates the use of constructors
// and destructors in the allocation and deallocation of memory.
#include <iostream>
#include <string>
using namespace std;

class Squares
{
private:
    int length;  // How long is the sequence
    int *sq;     // Dynamically allocated array
public:
    // Constructor allocates storage for sequence
    // of squares and creates the sequence
    Squares(int len);

    // Print the sequence
    void print() const;

    // Desctructor deallocates storage
    ~Squares();

};

/***********************************************
 * Implementation of class functions
 ***********************************************/

 Squares::Squares(int len)
 {
     length = len;
     sq = new int[length];
     int k;
     for (k = 0; k < length; k++)
     {
         sq[k] = (k+1)*(k+1);
     }
     // Trace
     cout << "Construct an object of size " << length << endl;
 }
 // Print the sequence
 void Squares::print() const
 {
     for (int k = 0; k < length; k++)
         cout << sq[k] << "  ";
     cout << endl;
 }
 // Desctructor deallocates storage
 Squares::~Squares()
 {
     delete [ ] sq;
     // Trace
     cout << "Destructor for object of size " << length <<  endl;
 }

//***********************************************
// Outputs the sequence of squares in a         *
// Squares object Client function               *
//***********************************************
void outputSquares(Squares *sqPtr)
{
    cout << "The list of squares is: ";
    sqPtr->print();

}
int main()
{
    //Squares test;
    Squares sqs(5);
    cout << "The first 5 squares are: ";
    sqs.print();

    // Main allocates a Squares object
    Squares *sqPtr = new Squares(3);
    outputSquares(sqPtr);
    // Main deallocates the Squares object
    delete sqPtr;
    sqPtr = 0;

    return 0;
}
