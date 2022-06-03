/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

#define MAX_SIZE 100

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {

	if(n<=0) 
		return NULL;

	int *row, col;

	*row = 10; // Randomly selected number, will be reallocated if exceeded
	col = 2*n;
	
	char** matrix = allocateMatrixChar(row, col);	

		
	
	return matrix;
}

void _generateParenthesis(int pos, int n, int open, int close, char** matrix, int row) {

	static char str[MAX_SIZE];	
	static int currRow = 0;

	if(close == n) {
		matrix[currRow++][0] = str;
		
		/* Extend matrix if needed */

		return;
	}
	else {
		if(open > close) {
			str[pos] = ')';
			_generateParenthesis(pos + 1, n, open, close + 1, matrix, currRow);
		}
		
		if(open < n) {
			str[pos] = '(';
			_generateParenthesis(pos + 1, n, open + 1, close, matrix, currRow);
		}	
	}
}

int main(void) {

	int* returnSize;
	char** matrix;

	matrix = generateParenthesis(2, returnSize);

	freeAllocatedMatrixChar(matrix, 10);

	printf("\nNot yet finished!\n\n");

	return EXIT_SUCCESS;
}
