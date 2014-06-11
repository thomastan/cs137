#include <stdbool.h>

int dayOfYear(int day, int month, int year) {
	int M[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month < 1 || month > 12 || year < 1583)
		return -1;

	bool isLeapYear = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
	bool valid = false;

	if (isLeapYear)
		valid = (day > 0 && day <= M[month - 1] + (month == 2 ? 1 : 0)) ? 1 : 0;
	else
		valid = (day > 0 && day <= M[month - 1]) ? true : false;

	if (!valid)
		return -1;

	int m, dayOfTheYear = 0;
	for (m = 0; m < month - 1; m++)
		dayOfTheYear += M[m] + (isLeapYear && m == 1 ? 1 : 0);

	return (dayOfTheYear += day);
}
