#include <stdio.h>

int max (int array[], int n);
int countValue (int array[], int n, int value);
void absolute (int array[], int n);
int isSorted (int array[], int n);
int isPermutation (int array[], int n);

int main (void)
{
  int i;
  int a[5] = {5,3,2,4,1};
  int b[5] = {-1, 0, 0, 0, 1};
  int c[5] = {-10, 9, -8 , 7, -6};

  printf("max(a, 5) = %d\n", max(a, 5));
  printf("countValue (a, 5, 1) = %d\n", countValue (a, 5, 1));
  printf("countValue (a, 5, 0) = %d\n", countValue (a, 5, 0));
  printf("isSorted (a, 5) = %d\n", isSorted (a, 5));
  printf("isPermutation (a, 5) = %d\n", isPermutation (a, 5));

  printf("max(b, 5) = %d\n", max(b, 5));
  printf("countValue (b, 5, 1) = %d\n", countValue (b, 5, 1));
  printf("countValue (b, 5, 0) = %d\n", countValue (b, 5, 0));
  printf("isSorted (b, 5) = %d\n", isSorted (b, 5));
  printf("isPermutation (b, 5) = %d\n", isPermutation (b, 5));

  absolute (c, 5);
  for (i = 0; i < 5; i++)
    printf ("c[%d] = %d\n", i, c[i]);
  return 0;
}
