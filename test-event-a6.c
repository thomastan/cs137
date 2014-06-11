#include <stdio.h>
#include "event.h"

int main (void)
{
  struct event schedule[] = {{{9,45},{9,55}},{{13,0},
                              {14,20}},{{15,0},{16,30}}};

  printf ("%d\n", freetime (schedule,3,8,0));
  printf ("%d\n", freetime (schedule,3,9,50));
  printf ("%d\n", freetime (schedule,3,13,0));
  printf ("%d\n", freetime (schedule,3,16,30));

  return 0;
}
