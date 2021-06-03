/*This is a P6 PPM image */
#include <stdio.h>

int main()
{
    int i = 0;
    /*Each PPM image must have a header that consist of the 'Magic number' 
    *P6 or P3, width (columns) and height (rows) and the maximum value that 
    *each red, green, and blue pixel can have.  */
    fprintf(stdout, "P6\n200 200 255\n");
    for(i = 0; i < 200*200; i++)
    {
        /*A P6 image is printed use %c%c%c with no spaces.  This is different
         *than the P3 which is %d %d %d with a space after each %d*/
        //Clemson orange
        fprintf(stdout, "%c%c%c", 234, 106, 32);
    }
    return 0;
}
