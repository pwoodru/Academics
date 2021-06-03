#include<stdio.h> 

/*When ran this program will cause an error. Explain Why? */

int main() 
{ 
	register int i = 10; 
	int* a = &i; 
	printf("%d", *a); 

	return 0; 
} 
