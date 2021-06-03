#include <iostream>
#include <cstddef> // for NULL
 
void print(int x)
{
	std::cout << "print(int): " << x << '\n';
}
 
void print(int *x)
{
	if (!x)
		std::cout << "print(int*): null\n";
	else
		std::cout << "print(int*): " << *x << '\n';
}
 
int main()
{
	int *x { NULL };
	print(x); 
	print(0); 
    /*this causes an error because Null is ambiguous.  NULL in C is translated 
     *to a zero and the compiler does not know if this should call the print 
     *that has the parameter of a pointer that might be 0 or it could be a 
     *pointer. */
	print(NULL); 

 
	return 0;
}