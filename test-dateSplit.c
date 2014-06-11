#include <stdio.h>

int dateSplit(int dayOfYear, int year, int *day, int *month);

void testDateSplit(int dayOfYear, int year)
{
  int day, month;

  if (dateSplit (dayOfYear, year, &day, &month))
    printf ("%d,%d => %d,%d\n", dayOfYear, year, day, month);
  else
    printf ("%d,%d => invalid\n", dayOfYear, year);
}

int main (void)
{
  testDateSplit (100, 2007);
  testDateSplit (100, 2008);
  testDateSplit (1, 2007);
  testDateSplit (1, 2008);
  testDateSplit (365, 2007);
  testDateSplit (366, 2007);
  testDateSplit (366, 2008);
  testDateSplit (-1, -1);

  return 0;
}
