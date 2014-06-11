#define TRUE 1
#define FALSE 0

int max(int array[], int n) {
	int i, max = 0;
	for (i = 0; i < n; i++)
		if (array[i] > max)
			max = array[i];

	return max;
}

int countValue(int array[], int n, int value) {
	int i, count = 0;
	for (i = 0; i < n; i++)
		if (array[i] == value)
			count++;

	return count;
}

void absolute(int array[], int n) {
	int i;
	for (i = 0; i < n; i++)
		array[i] = array[i] < 0 ? -array[i] : array[i];
}

int isSorted(int array[], int n) {
	int i;
	for (i = 0; i < n - 1; i++)
		if (array[i] > array[i + 1])
			return FALSE;

	return TRUE;
}

int isPermutation(int array[], int n) {
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 0; j < n; j++)
			if (i == array[j])
				break;
			else if (j == n - 1 && array[j] != i)
				return FALSE;

	return TRUE;
}
