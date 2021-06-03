#include "SortedNumberList.h"

//*********************************************
// Adds a number to the sorted list.          *
// This function overrides add in NumberList. *
//*********************************************
void SortedNumberList::add(double number) 
{
   ListNode *nodePtr, *previousNodePtr;

   if (head == NULL || head->value >= number)
   {
      // A new node goes at the beginning of the list
      head = new ListNode(number, head);
   }
   else
   {
      previousNodePtr = head;
      nodePtr = head->next;

      // Find the insertion point
      while (nodePtr != NULL && nodePtr->value < number)
      {
         previousNodePtr = nodePtr;
         nodePtr = nodePtr->next;
      }
      // Insert the new node just before nodePtr
      previousNodePtr->next = new ListNode(number, nodePtr);
   }
}

