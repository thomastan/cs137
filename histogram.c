#include <stdlib.h>  // for calloc() to zero-init an array
#include <stddef.h>  // the null pointer NULL is defined inside here
int *histogram(const int *a, int n, int *m) {
	int i, max = -1, *hist = NULL;

	for (i = 0; i < n; i++)
		if (a[i] > max)
			max = a[i];

	*m = max + 1;
	hist = (int *) calloc((max + 1), sizeof(int)); // auto init elements to zero

	for (i = 0; i < n; i++)
		hist[a[i]]++;

	return hist;
}
