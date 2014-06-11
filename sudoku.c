#include <stdbool.h>  // all subroutines use this library's definitions
#define TRUE 1  // sudoku() uses these for more safety with Marmoset
#define FALSE 0

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

bool validSub(int grid[9][9], int index) {
	int i, j, result[9];

	int row = index / 3;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result[i * 3 + j] = grid[row + i][i + j];

	return isPermutation(result, 9);
}

void takeRow(int index, int grid[9][9], int* result) {
	int j;
	for (j = 0; j < 9; j++)
		result[j] = grid[index][j];
}

void takeCol(int index, int grid[9][9], int* result) {
	int i;
	for (i = 0; i < 9; i++)
		result[i] = grid[i][index];
}

void takeSubGrid(int index, int grid[9][9], int* result) {
	int i, j, row = index / 3, col = index % 3; // (row, col) is the top-left

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			result[i * 3 + j] = grid[row * 3 + i][col * 3 + j];
}

int sudoku(int grid[9][9]) {
	int i;

	// If any 1 of the 9 rows, columns or sub-grid's fail to be a permutation of
	// the digits 1 through 9, the grid is a FALSE sudoku grid:

	for (i = 0; i < 9; i += 1) {
		int temp[9];

		takeRow(i, grid, temp);
		if (!isPermutation(temp, 9))
			return FALSE;

		takeCol(i, grid, temp);
		if (!isPermutation(temp, 9))
			return FALSE;

		takeSubGrid(i, grid, temp);
		if (!isPermutation(temp, 9))
			return FALSE;
	}

	return TRUE;
}
