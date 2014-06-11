#include <stdio.h>

int main(void) {
	int a, b;

	scanf("%d", &a);
	scanf("%d", &b);

	if (b == 0) {
		puts("Divide by zero!");
		return 1;
	}

	int isNegative = 0; // boolean value: 0 is false, non-zero is true
	if ((a < 0 && b < 0) || (a >= 0 && b > 0))
		isNegative = 0;
	else if (a > 0 && b < 0 && a != 0)
		isNegative = 1;
	else if (a < 0 && b > 0 && a != 0)
		isNegative = 1;

	// GCD
	int A = a, B = b, tmp;

	while (A != 0)
		tmp = A, A = B % A, B = tmp;

	a = a / B;
	b = b / B;

	int absA = a, absB = b;
	if (a < 0)
		absA = -absA;
	if (b < 0)
		absB = -absB;

	// Convert to mixed fraction
	int wholePart = 0, remainder;
	if (absA > absB) {
		wholePart = absA / absB;
		remainder = absA % absB;

		if (isNegative) {
			wholePart = -wholePart; // also, fraction part should be +ve
			a = absA;
			b = absB;
		}
	}

	// Output
	if (wholePart != 0)
		if (remainder != 0)
			printf("%d %d/%d\n", wholePart, remainder, b);
		else
			printf("%d\n", wholePart);
	else if (absA == 1 && absB == 1)
		if (isNegative)
			puts("-1");
		else
			puts("1");
	else if (isNegative)
		printf("-%d/%d\n", absA, absB);
	else
		printf("%d/%d\n", absA, absB); // prevent -a/-b situations

	return 0;
}
