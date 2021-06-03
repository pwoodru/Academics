#include<stdio.h> 

int main() 
{ 

    /*This program causes an error. Explain why. */
	int i = 10; 
	register static int* a = &i; 
	printf("%d", *a); 
	getchar(); 
	return 0; 
} 
