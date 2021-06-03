// This program illustrates the building
// and traversal of a linked list.

#include <iostream>
#include <fstream>
using namespace std;

/*The struct has a constructor inside it.*/
struct ListNode
{
     double value;
     ListNode *next;
     // Constructor
     ListNode(double value1, ListNode *next1 = NULL)
     {
       value = value1;
       next = next1;
     }
};

int main()
{
   double number;                 // Used to read the file (10, 20, 30, 40)
   ListNode *numberList = NULL;   // List of numbers

   // Open the file
   ifstream numberFile("numberFile.dat");
   if (!numberFile)
   {
      cout << "Error in opening the file of numbers.";
      exit(1);
   }
   // Read the file into a linked list
   cout << "numbers in the file are: " << endl;
   while (numberFile >> number)
   {
      cout << number << "  ";
      // Create a node to hold this number
      /*look at this from right to left.  first the old value of
       *head is used in the constructor, and then the address is returned
       *from the new operator is assigned to head*/
      numberList = new ListNode(number, numberList);
   }
   // Traverse the list while printing
   cout << endl << "The contents of the list are: " << endl;

   /*This points ptr to the beginning of the list.*/
   ListNode *ptr = numberList;

   while (ptr != NULL)
   {
      /*Go to where ptr is pointing and get the value and print*/

      cout << ptr->value << "  "; // Process node
      /*Now point ptr to where ptr next is pointing Which is the next
       *node*/
      ptr = ptr->next;
          // Move to next node
   }
   return 0;
}
