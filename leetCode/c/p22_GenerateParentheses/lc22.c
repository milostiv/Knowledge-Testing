/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../mylib/mylib.h"

#define MAX_SIZE 100

static char str[MAX_SIZE];

void _generateParenthesis(int pos, int n, int open, int close) {
 
    if(close == n) {
        printf("%s \n", str);
        
		return;
    }
    else {
        if(open > close) {
        	str[pos] = '}';
        	_generateParenthesis(pos + 1, n, open, close + 1);
        }
 
        if(open < n) {
            str[pos] = '{';
            _generateParenthesis(pos + 1, n, open + 1, close);
        }
    }	
}

void generateParenthesis(int n, int* returnSize) {

	if(n > 0) 
		_generateParenthesis(0, n, 0, 0);
	
	return;
}

int main(void) {

	int n;
	int* returnSize;

	// Test 1:

	n = 3;	
	printf("N = %d:\n", n);
	generateParenthesis(n, returnSize);
	memset(str,0,sizeof(str));	// Clear string
	printf("\n");

	// Test 2:

	n = 1;	
	printf("N = %d:\n", n);
	generateParenthesis(n, returnSize);	
	memset(str,0,sizeof(str));	// Clear string
	printf("\n");

	// Test 3:	

	n = 4;	
	printf("N = %d:\n", n);
	generateParenthesis(n, returnSize);	
	memset(str,0,sizeof(str));	// Clear string
	printf("\n");

	return EXIT_SUCCESS;
}
