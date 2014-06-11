#include <stdio.h>
#include <stdlib.h>

char *alphabetic (const char *s);

int main (void)
{
  char *a, *b, *c;
  a = alphabetic ("Ready... aim... fire!");
  b = alphabetic ("***");
  c = alphabetic ("*a*b*c*");
  
  printf ("%s\n", a);
  printf ("%s\n", b);
  printf ("%s\n", c);

  free(a);
  free(b);
  free(c);
  
  return 0;
}
