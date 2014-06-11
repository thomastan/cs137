#include <stdio.h>

int contains(char *s, char *t);

int main(void)
{
  printf ("%d\n", contains ("I wanna shoot something!", "thing"));
  printf ("%d\n", contains ("Let's get in range!", "ge"));
  printf ("%d\n", contains ("Wanna see the fireworks?", "wanna"));
  printf ("%d\n", contains ("Look at the pretty explosions!", " "));
  printf ("%d\n", contains ("Kaboom!", ""));
  
  printf ("%d\n", contains ((char *) 0, "aaa"));
  printf ("%d\n", contains ("aaa", (char *) 0));
  printf ("%d\n", contains ((char *) 0, (char *) 0));

  return 0;
}
