#include <stdio.h>

char *c[] = {"HelloWorld", "One", "Two", "Three"};
char **cp[] = {c+3, c+2, c+1, c+0};
char ***cpp = cp;

int main()
{
    printf("**++cpp = %s \n", **++cpp);
    printf("*--*++cpp+3 = %s \n", *--*++cpp+3);
    printf("*cpp[-2] + 3 = %s \n", *cpp[-2]+3);
    printf("cpp[-1][-1]+1 = %s \n",cpp[-1][-1]+1);
 
    return 0;
}

/*This is an example of a triple pointer. It is rather complicated and some of
*the dereferencing is complicated. 
*Your task is to run this code.  Then you are to explain what each of the 
*print statements do. You can use drawings or words or a combination of each.
*Be detailed enough to convince me you understand this.   
*/