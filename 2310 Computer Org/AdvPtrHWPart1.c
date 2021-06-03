#include <stdio.h>
int main()
{
    int arr[5] = {0,1,2,3,4};

    /*The expression (&arr + 1) is actually an addess just past the end of 
     *arr.  This is due to the fact that &arr contains an address of an item of 
     *size 5 times the size of an integer.  Therefore when you do something
     *like (&arr + 1) the pointer is incremented 5 * the size of an integer on
     *my computer that is 20 bytes*/
    /*Let's try to convince ourselves of this.*/
     /*Task 1:
       Write a loop that will print the address of each element of arr.
     */
    printf("Task 1:\n");
    printf("Print address of each element of arr: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", &arr[i]);
    }
    printf("\n");

    int *ptr = (int*)(&arr+1);

    /*Task 2: Write a statement that will print the value of ptr.  Keep in mind
     *ptr is a pointer.  What type of data does a pointer hold. 
     */
    printf("Task 2:\n");
    printf("Pointer value at (&arr+1): %d\n", *ptr);

    /*Task 3: Using array arithmatic and pointer arithmatic, not subscripts. 
     *1.Write a statement that will print first the value of (a+1), don't forget 
     *to dereference this. 
     *2.Next you are to print the value of the last element in 
     *arr using ptr. Think about where ptr is pointing to and how you can print 
     *this value without using subscripts.  Once you figure this out, now think
     *about how you can print the last element of arr using ptr with subscripts.
     *Example ptr[?] is using a subscript. *(ptr ?? ) is without subscripts. 
     *3.Write a statement that will print the value of the last element of arr
     *using ptr and with and without subscripts. */

    printf("Task 3: \n");
    printf("1. Print value of (a+1): %d\n", *ptr);
    printf("2. Last element of arr using ptr without subscripts: %d\n", *(ptr - 1));
    printf("3. Print last element using ptr, with and without subscripts: ");
    printf("%d %d\n", *(ptr - 1), ptr[-1]);

    return 0;
}
/*Discuss some interesting things you have learned about pointers in this
 *exercise. */

