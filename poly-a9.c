#include <stdio.h>    // printf()
#include <stdlib.h>   // malloc(), calloc(), realloc(), free()
#include "poly.h"

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

struct poly *polyCreate() {
	struct poly *p = (struct poly *) malloc(sizeof(struct poly));
	p->degree = 0;
	p->coeff = (double *) calloc(p->degree + 1, sizeof(double));
	return p;
}

struct poly *polyDelete(struct poly *p) {
	free(p->coeff), p->degree = 0;
	return p;
}

struct poly *polySetCoefficient(struct poly *p, int i, double value) {
	if (i <= p->degree)
		p->coeff[i] = value;
	else {
		p->coeff = (double *) realloc(p->coeff, (i + 1) * sizeof(double));
		p->coeff[i] = value;

		int j;
		for (j = i - 1; j > p->degree + 1; j--)
			p->coeff[j] = 0.0;

		p->degree = i;
	}

	return p;
}

double polyGetCoefficient(struct poly *p, int i) {
	return i <= p->degree ? p->coeff[i] : 0;
}

int polyDegree(struct poly *p) {
	return p->degree;
}

void polyPrint(struct poly *p) {
	int i, printCount = 0;

	for (i = p->degree; i >= 0; i--) {
		if (p->coeff[i] == 0) {
			printf("%s", i == 0 && printCount == 0 ? "0" : "");
			continue;
		}

		// leading coefficient may use its own negative sign
		// for any other coefficients, the sign surrounded by spaces precedes it
		if (printCount == 0)
			printf("%s", (p->coeff[i] < 0 ? "-" : ""));
		else
			printf("%s", (p->coeff[i] < 0 ? " - " : " + "));

		if (p->coeff[i] != 1 && p->coeff[i] != -1 || i == 0) // hide unit coeffs
			printf("%g", p->coeff[i] < 0 ? -p->coeff[i] : p->coeff[i]);

		printCount++;

		// print pronumeral, but only if necessary
		printf("%s", (i > 0 && (p->coeff[i] != 0) ? "x" : ""));

		if (i >= 2)
			printf("^%d", i); // only print the exponent if its a square or more
	}

	puts("");
}

struct poly *polyCopy(struct poly *p) {
	struct poly *q = (struct poly *) malloc(sizeof(struct poly));
	q->coeff = (double *) malloc(sizeof(double) * (p->degree + 1));
	q->degree = p->degree;

	int i;
	for (i = 0; i <= p->degree; i++)
		q->coeff[i] = p->coeff[i];

	return q;
}

struct poly *polyAdd(struct poly *p0, struct poly *p1) {
	struct poly *q = (struct poly *) malloc(sizeof(struct poly));
	int i;

	q->degree = max(p0->degree, p1->degree);
	q->coeff = (double *) malloc(sizeof(double) * (q->degree + 1));
	for (i = q->degree; i >= 0; i--)
		q->coeff[i] = p0->coeff[i] + p1->coeff[i];

	return q;
}

struct poly *polyMultiply(struct poly *p0, struct poly *p1) {
	struct poly *q = (struct poly *) malloc(sizeof(struct poly));
	int i, j;

	q->degree = p0->degree + p1->degree;
	q->coeff = (double *) calloc(q->degree + 1, sizeof(double));

	// For polynomials A(x) and B(x), its product C(x) = A(x)B(x) has 
	// coefficients c_1, c_2, ..., c_{m + n} given by the convolution of vectors
	// (a_0, a_1, ..., a_n) and (b_0, b_1, ..., b_m):

	//    c_i = \sum_{j = 0}^{i} a_j * b_{i - j}

	for (i = 0; i <= p0->degree + p1->degree; i++)
		for (j = 0; j <= i; j++)
			if (j <= p0->degree && (i - j) <= p1->degree)
				q->coeff[i] += p0->coeff[j] * p1->coeff[i - j];

	return q;
}

struct poly *polyPrime(struct poly *p) {
	struct poly *q = (struct poly *) malloc(sizeof(struct poly));
	q->coeff = (double *) malloc(sizeof(double) * (p->degree - 1));
	q->degree = p->degree - 1;

	int i;
	for (i = 0; i <= p->degree - 1; i++)
		q->coeff[i] = (i + 1) * p->coeff[i + 1];

	return q;
}

double polyEval(struct poly *p, double x) {
	double sum = 0.0, xPowered = 1.0;
	int i, j;
	for (i = p->degree + 1; i >= 0; i--) {
		for (j = 0, xPowered = 1.0; j < i; j++)
			xPowered *= x;
		sum += p->coeff[i] * xPowered;
	}
	return sum;
}
