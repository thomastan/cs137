#ifndef _FRACTION_H_
#define _FRACTION_H_

struct fraction {
	int whole;
	int remainder;
	int divisor;
};

struct fraction fractionCreate(int numerator, int denominator); 
struct fraction fractionAdd(struct fraction a, struct fraction b); 
struct fraction fractionSubtract(struct fraction a, struct fraction b); 
struct fraction fractionMultiply(struct fraction a, struct fraction b); 
struct fraction fractionDivide(struct fraction a, struct fraction b); 
void fractionPrint(struct fraction f); 

#endif
