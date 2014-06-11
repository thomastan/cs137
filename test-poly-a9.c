#include <stdio.h>
#include "poly.h"

int main (void)
{
  struct poly *p0 = polySetCoefficient (polySetCoefficient (polySetCoefficient (
                                      polyCreate() , 0, 4.0), 1, -1.0), 10, 2.0);
  struct poly *p1 = polyCopy (p0);
  struct poly *p2, *p3, *p4;

  printf ("%g\n", polyGetCoefficient (p0, 10));
  printf ("%g\n", polyGetCoefficient (p0, 100));
  printf ("%d\n", polyDegree (p0));
  polyPrint (p0);
  polyPrint (p1);
  polySetCoefficient (p1, 2, 1.0/2.0);
  polyPrint (p1);
  p2 = polyAdd (p0, p1);
  polyPrint (p2);
  p3 = polyMultiply (p0, p1);
  polyPrint (p3);
  p4 = polyPrime (p0);
  polyPrint (p4);
  printf ("%g\n", polyEval (p0, 0.0));
  printf ("%g\n", polyEval (p0, 1.0));
  printf ("%g\n", polyEval (p0, 2.0));
  p0 = polyDelete (p0);
  p1 = polyDelete (p1);
  p2 = polyDelete (p2);
  p3 = polyDelete (p3);
  p4 = polyDelete (p4);

  return 0;
}
