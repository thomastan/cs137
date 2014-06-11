#include <string.h>

int contains(char *s, char *t) {
	int count = 0, pos = 0, slength, tlength;

	if (!s || !t)
		return 0;

	slength = strlen(s), tlength = strlen(t);
	if (slength == 0 || tlength == 0)
		return 0;

	while (pos++ <= slength)
		if (strncmp(s++, t, tlength) == 0) {
			count++, pos += tlength - 1;
			s += (pos <= slength) ? (tlength - 1) : 1;
		}

	return count;
}
