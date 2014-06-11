#include <stdio.h>

int main(void) {
	int num, reverse = 0, numDigits = 0;
	scanf("%d", &num);

	while (num != 0) {
		reverse = (num % 10) + reverse * 10;
		num /= 10;
		numDigits++;
	}

	printf("%0*d\n", numDigits, reverse);

	return 0;
}