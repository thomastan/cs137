#include <stdio.h>
#include <stdbool.h>
#include "fraction.h"

#define abs(x) ((x) < 0 ? -(x) : (x))

struct fraction fractionCreate(int numerator, int denominator) {
	struct fraction result;
	result.whole = 0, result.divisor = 0;

	if (denominator == 0)
		return result;

	int a = numerator, b = denominator, tmp;

	bool isNegative = false;
	if ((a < 0 && b < 0) || (a >= 0 && b > 0))
		isNegative = false;
	else if ((a > 0 && b < 0 || a < 0 && b > 0) && a != 0)
		isNegative = true;

	while (b != 0) // a = gcd(a, b)
		tmp = b, b = a % b, a = tmp;

	if (abs(numerator) > abs(denominator)) { // convert to mixed fraction
		result.whole = abs(numerator / denominator) * (isNegative ? -1 : 1);
		result.remainder = abs(numerator % denominator) / a;
	} else
		result.remainder = abs(numerator % denominator) / (isNegative ? -a : a);
	result.divisor = abs(denominator / a);

	return result;
}

struct fraction fractionAdd(struct fraction a, struct fraction b) {
	struct fraction result = fractionCreate(0, 0);
	if (a.divisor == 0 || b.divisor == 0)
		return result;

	// The addition of fractions a and b here, where a and/or b are possibly
	// negative, is done in mixed form, WITHOUT firstly converting to improper
	// form to decrease the chance of integer overflows.

	int signA = (a.whole != 0 && a.whole < 0 || a.remainder < 0) ? -1 : 1;
	int signB = (b.whole != 0 && b.whole < 0 || b.remainder < 0) ? -1 : 1;

	result.whole = a.whole * signA + b.whole * signB;
	result.divisor = a.divisor * b.divisor; // positive, unsimplified

	// temporary variable that holds the sum's numerator (unsimplified)
	int t = abs(a.remainder * b.divisor) * signA;
	t = t + abs(b.remainder * a.divisor) * signB;

//	printf("signA signB: %d %d\n", signA, signB);
//	printf("basic sum: %d %d\\%d\n", result.whole, result.divisor, t);

	// correct the (t / result.divisor) term
	if (abs(t) > abs(result.divisor)) // convert to mixed fraction
		result.whole += t / abs(result.divisor);

//	printf("result.whole + (t / result.divisor) = + %d\n", t / result.divisor);

	// simplify remainder ÷ divisor (using the gcd)
	int A = result.divisor; // divisor (usually the bigger, so use as A for GCD)
	int B = abs(t % result.divisor); // remainder
	int tmp, copyA = A, copyB = B;

//	printf("A B: %d %d\n", A, B);

	while (B != 0) // A = gcd(A, B)
		tmp = B, B = A % B, A = tmp;

//	printf("gcd(A, B) = %d\n", A);

	result.remainder = copyB / A;
	result.divisor = copyA / A;
	return result;
}

struct fraction fractionSubtract(struct fraction a, struct fraction b) {
	struct fraction init = fractionCreate(0, 0);
	if (a.divisor == 0 || b.divisor == 0)
		return init;

	if (b.whole != 0)
		b.whole = -b.whole;
	else
		b.remainder = -b.remainder;

	return fractionAdd(a, b);
}

struct fraction fractionMultiply(struct fraction a, struct fraction b) {
	struct fraction init = fractionCreate(0, 0);
	if (a.divisor == 0 || b.divisor == 0)
		return init;

	// firstly convert both fractions to improper form
	a.remainder += a.whole * a.divisor;
	b.remainder += b.whole * b.divisor;
	a.whole = 0, b.whole = 0;

	return fractionCreate(a.remainder * b.remainder, a.divisor * b.divisor);
}

struct fraction fractionDivide(struct fraction a, struct fraction b) {
	struct fraction init = fractionCreate(0, 0);
	if (a.divisor == 0 || b.divisor == 0)
		return init;

	// firstly convert both fractions to improper form
	a.remainder += a.whole * a.divisor;
	b.remainder += b.whole * b.divisor;
	a.whole = 0, b.whole = 0;

	return fractionCreate(a.remainder * b.divisor, a.divisor * b.remainder);
}

void fractionPrint(struct fraction f) {
	if (f.divisor == 0) {
		puts("Divide by zero!");
		return;
	}

	if (f.whole != 0)
		if (f.whole != 0 && f.remainder != 0)
			printf("%d %d/%d\n", f.whole, f.remainder, f.divisor);
		else
			printf("%d\n", f.whole);
	else
		printf("%d/%d\n", f.remainder, f.divisor);
}
