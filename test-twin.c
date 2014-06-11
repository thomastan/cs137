#include <stdio.h>

void testTwin (int number)
{
  if (isTwin(number))
    printf ("%d is a twin prime\n", number);
  else
    printf ("%d is not a twin prime\n", number);
}

int main (void)
{
  testTwin (7);
  testTwin (13);
  testTwin (823);
  testTwin (2);
  testTwin (23);
  testTwin (100);
  testTwin (-3);
}
