#include <stdio.h>
#include "event.h"

int main (void)
{
  struct event schedule[] = {
   {{15,0},{16,30}},
   {{9,0},{9,15}},
   {{13,0},{14,20}},
   {{17,15},{18,0}},
   {{9,45},{9,55}},
  };

  int i;
  struct event event0 = {{10,0},{10,30}};
  struct event event1 = {{14,20},{15,0}};
  struct event event2 = {{17,0},{17,30}};
  struct event event3 = {{15,30},{16,0}};

  printf ("%d\n", available (schedule, sizeof(schedule)/sizeof(schedule[0]), event0));
  printf ("%d\n", available (schedule, sizeof(schedule)/sizeof(schedule[0]), event1));
  printf ("%d\n", available (schedule, sizeof(schedule)/sizeof(schedule[0]), event2));
  printf ("%d\n", available (schedule, sizeof(schedule)/sizeof(schedule[0]), event3));

  sortSchedule (schedule, sizeof(schedule)/sizeof(schedule[0]));

  for (i = 0; i < sizeof(schedule)/sizeof(schedule[0]); i++)
    printf ("%02d:%02d - %02d:%02d\n", schedule[i].start.hour, schedule[i].start.minute, schedule[i].end.hour, schedule[i].end.minute);

  return 0;
}
