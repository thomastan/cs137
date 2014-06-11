#include <stdio.h>

void revlist() {
	int input;
	scanf("%d", &input);

	if (input != 0)
		revlist();
	printf("%d\n", input);
}

int main() {
	revlist();
	return 0;
}