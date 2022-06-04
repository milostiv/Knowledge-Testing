/* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../mylib/mylib.h"

#define MAX_SIZE 100

static char str[MAX_SIZE];

void _generateParentheses(int pos, int n, int open, int close) {
 
    if(close == n) {
        printf("%s \n", str);
        
		return;
    }
    else {
        if(open > close) {
        	str[pos] = ')';
        	_generateParentheses(pos + 1, n, open, close + 1);
        }
 
        if(open < n) {
            str[pos] = '(';
            _generateParentheses(pos + 1, n, open + 1, close);
        }
    }	
}

void generateParentheses(int n, int* returnSize) {

	if(n > 0) 
		_generateParentheses(0, n, 0, 0);
	
	return;
}

int main(void) {

	int n;
	int* returnSize;

	// Test 1:

	n = 3;	
	printf("Test 1: N = %d\n", n);
	generateParentheses(n, returnSize);
	memset(str,0,sizeof(str));	// Clear string
	printf("\n");

	// Test 2:

	n = 1;	
	printf("Test 2: N = %d\n", n);
	generateParentheses(n, returnSize);	
	memset(str,0,sizeof(str));	// Clear string
	printf("\n");

	// Test 3:	

	n = 4;	
	printf("Test 3: N = %d\n", n);
	generateParentheses(n, returnSize);	
	memset(str,0,sizeof(str));	// Clear string
	printf("\n");

	return EXIT_SUCCESS;
}
