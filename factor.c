#include <stdio.h>

void factor(int number) { // assuming number is positive
	int p = 2;

	printf("%d = ", number);

	if (number <= 3) {
		printf("%d\n", number);
		return;
	}

	while (p < number)
		if (number % p == 0)
			printf("%d*", p), number /= p;
		else
			p += p == 2 ? 1 : 2;

	printf("%d\n", p);
}
