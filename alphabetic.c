#include <stdlib.h>
#include <string.h>

char *alphabetic(const char *s) {
	int i, j = 0, count = 0;

	for (i = 0; i < strlen(s); i++)
		if (s[i] >= 65 && s[i] < (65 + 26)) // uppercase
			count++;
		else if (s[i] >= 97 && s[i] < (97 + 26)) // lowercase
			count++;

	char *filtered = (char *) malloc((count + 1) * sizeof(char));
	for (i = 0; i < strlen(s); i++)
		if (s[i] >= 65 && s[i] < 91 || s[i] >= 97 && s[i] < 123)
			filtered[j++] = s[i];
	filtered[j] = '\0';

	return filtered;
}
