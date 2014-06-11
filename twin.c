#include <stdbool.h>  // for internal boolean values
#include <math.h>     // for sqrt()
#define FALSE 0       // return these boolean values (for safety with Marmoset)
#define TRUE 1

bool isPrime(int number) {
	if (number == 0 || number == 1 || number % 2 == 0 || number % 3 == 0)
		return (number == 2 || number == 3) ? true : false;

	// Primality testing is more efficiently done using the fact that all prime
	// numbers can be expressed as 6k +/- 1 <= sqrt(n) for k = 1, 2, 3, ...
	// while noting at the same time that the converse of this is not true.
	int j;
	for (j = 5; j <= sqrt(number); j += 6)
		if (number % j == 0 || number % (j + 2) == 0)
			return false;

	return true;
}

bool isTwin(int number) {
	if (isPrime(number) && (isPrime(number - 2) || isPrime(number + 2)))
		return TRUE;
	else
		return FALSE;
}
