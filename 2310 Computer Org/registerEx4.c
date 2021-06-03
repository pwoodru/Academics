#include <stdio.h> 

/*This code will cause an error. Explain Why? */
register int x = 10; 
int main() 
{ 
	register int i = 10; 
	printf("%d\n", i); 
	printf("%d", x); 
	return 0; 
} 
