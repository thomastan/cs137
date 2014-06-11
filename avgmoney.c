#include <stdio.h>

void printAverageAmount(double money[], int n) {
	int i, avgDolls, avgCents;
	double sum = 0;
	for (i = 0; i < n; i++)
		sum += money[i];

	avgDolls = (int) (sum / n);
	avgCents = (int) 100 * ((sum / n) - avgDolls);

	printf("Everyone gets %d dollar(s) and %d cent(s).\n", avgDolls, avgCents);
}
