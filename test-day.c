#include <stdio.h>

int dayOfYear(int day, int month, int year);

int testDayOfYear(int day, int month, int year)
{
  printf ("%d/%d/%d => %d\n", day, month, year,
          dayOfYear(day, month, year));
}

int main (void)
{
  testDayOfYear (1, 1, 2008);
  testDayOfYear (29, 2, 2008);
  testDayOfYear (29, 2, 2009);
  testDayOfYear (26, 9, 2008);
  testDayOfYear (31, 12, 2008);
  testDayOfYear (31, 12, 2009);
  testDayOfYear (100, 1, 2008);
  testDayOfYear (1, 100, 2008);
  testDayOfYear (1, 1, 100);
}