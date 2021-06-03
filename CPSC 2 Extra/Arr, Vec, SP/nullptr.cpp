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
	int *x { };//this can be set to {nullptr} or implied {}
	print(x); // calls print(int*)
    print(0); // calls print(int)
	print(nullptr); // calls print(int*) as desired
 
	return 0;
}