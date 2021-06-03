#include <stdio.h>

int f1(int, int*);
int f2(int, int*);

int main()
{
    int a, *b;

    a = 6; b = &a;
    printf("b = %d\n", *b);
    printf("%d\n", f1(a,b));

    return 0;

}

int f1(int x, int *y)
{
    int a, b;
    b = *y;
    printf("b = %d\n", b);
    *y+=3;
    printf("*y = %d\n", *y);
    printf("b = %d\n", b);
    a = *y;
    printf("a = %d\n", a);
    printf("x before = %d\n", x);
    x = f2(a,&b);
    printf("x after = %d\n", x);
    x +=4;
    printf("x + 4 = %d\n", x);
    return (f2(a,&x) + a + x);
}

int f2(int s, int *t)
{
    printf("s = %d\n", s);
    printf("*t = %d\n", *t);
    static int a = 4;
    a +=s + *t;
    printf("a = %d\n", a);
    return a;
}

/*Trace through this program on paper.  You must show the state 
 *of the variables at each step and a short explanation. You will need to 
 *convince me you actually walked through this and did not simply run it to get
 *the answer. */