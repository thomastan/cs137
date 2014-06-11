#include <string.h>  // for strcpy()
int rpsls(const char *player1, const char *player2) {
	char choice[5][10] = { "rock", "paper", "scissors", "lizard", "Spock" };

	// RPSLS is a complete graph.  Therefore, we use an adjacency matrix, where
	// diagonal entries A[i][i] == 0 and A[i][j] == '1' indicates 'i' is a
	// winner and 'j' is at loss.  From the opposite perspective, A[j][i] = '-1'
	// is indicative of j's loss.  From A[i][j] == -A[j][i] we know that A is
	// skew-symmetric and that -A = A^T.  For RPSLS:
	//     sum{j} A[i][j] = 0,     sum{i} A[i][j] = 0,     A[i][j] in {-1, 0, 1}

	if (!player1 || !player2)
		return 0;

	const int A[5][5] = { //
			/* A= */{ 0, -1, 1, 1, -1 }, //
					{ 1, 0, -1, -1, 1 }, //
					{ -1, 1, 0, 1, -1 }, //
					{ -1, 1, -1, 0, 1 }, //
					{ 1, -1, 1, -1, 0 } };
	int i, choice1 = -1, choice2 = -1, numChoices = 5;

	for (i = 0; i < numChoices; i++) {
		if (strcmp(player1, choice[i]) == 0)
			choice1 = i;
		if (strcmp(player2, choice[i]) == 0)
			choice2 = i;
	}

	return A[choice1][choice2];
}
