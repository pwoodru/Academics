#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void int2bin(int num, int arr[8]);

int main() {

  char* this = "Hello friend";
  int i, j, k, m, n, dec;
  int red, green, blue;
  int thisCount = 0;
  int arr[9];
  int test[9];

  printf("Test array: \n");
  for (k = 0; k < 9; k++) {
    test[k] = k;
    printf("%d", test[k]);
  }
  printf("\n");

  int length = strlen(this);

  printf("message length = %d\n", length);

  for (i = 0; i < length; i++) {
    dec = this[thisCount];
    printf("dec to be converted to binary: %d\n", dec);
    int2bin(dec, arr);

    for (j = 0; j < 9; j++) {
      printf("%d", arr[j]);
    }
    printf("\n");

    printf("Binary individually added to each element: \n");
    for (m = 0; m < 9; m++) {
      test[m] = test[m] + arr[m];
      printf("%d", test[m]);
    }
    printf("\n");

    //resetting array (not needed for PA1)
    for (n = 0; n < 9; n++) {
      test[n] = n;
    }

    thisCount++;
  }



  return 0;
}

void int2bin(int num, int arr[9])
{
  int a;

  for (a = 8; a >= 0; a--) {
    arr[a] = num % 2;

    if (num > 0) {
        num = num / 2;
    }
    else {
        arr[a] = 0;
    }
  }

}
