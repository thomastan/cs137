#include <stdbool.h>  // for boolean variables
#define VALID 1       // boolean return values
#define INVALID 0

int dateSplit(int dayOfYear, int year, int *day, int *month) {
	int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, i;

	if (dayOfYear < 1 || dayOfYear > 366 || year < 1583)
		return INVALID;

	*month = 0;

	bool isLeapYear = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	if (dayOfYear == 366 && !isLeapYear)
		return INVALID;

	for (i = 0; i < 12; i++)
		if (dayOfYear - (M[i] + (isLeapYear && i == 1 ? 1 : 0)) > 0) {
			dayOfYear -= (M[i] + (isLeapYear && i == 1 ? 1 : 0));
			(*month)++;
		} else {
			*day = dayOfYear;
			break;
		}

	(*month)++; // within this function, months were indexed starting from 0
	return VALID;
}
