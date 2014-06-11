#include <stdio.h>

void polyPrint(double a[], int n) {
	int i, printCount = 0;

	for (i = n - 1; i >= 0; i--) {
		if (a[i] == 0) {
			printf("%s", i == 0 && printCount == 0 ? "0" : "");
			continue;
		}

		// leading coefficient may use its own negative sign
		// for any other coefficients, the sign surrounded by spaces precedes it
		if (printCount == 0)
			printf("%s", (a[i] < 0 ? "-" : ""));
		else
			printf("%s", (a[i] < 0 ? " - " : " + "));

		if (a[i] != 1 && a[i] != -1 || i == 0) // hide unit coefficents
			printf("%g", a[i] < 0 ? -a[i] : a[i]);

		printCount++;

		// print pronumeral, but only if necessary
		printf("%s", (i > 0 && (a[i] != 0) ? "x" : ""));

		if (i >= 2)
			printf("^%d", i); // only print the exponent if its a square or more
	}

	puts("");
}
