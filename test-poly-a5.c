void polyPrint (double a[], int n);

int main (void)
{
  double a[] = {2.0, 3.0, 4.0};
  double b[] = {0.0, 3.0, 0.0};
  double c[] = {2.0, -2.0, 9.0, -1.0, 8.0, -7.0};
  double d[] = {2.0, 0.0, 0.0, 0.0, 0.0, 1.0};
  double e[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  double f[] = {2.0/3.0, 1.0/7.0, 9.0/13.0};

  polyPrint (a, sizeof(a)/sizeof(a[0]));
  polyPrint (b, sizeof(b)/sizeof(b[0]));
  polyPrint (c, sizeof(c)/sizeof(c[0]));
  polyPrint (d, sizeof(d)/sizeof(d[0]));
  polyPrint (e, sizeof(e)/sizeof(e[0]));
  polyPrint (f, sizeof(f)/sizeof(f[0]));

  return 0;
}
