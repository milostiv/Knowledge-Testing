/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "../../../mylib/mylib.h" 

bool bracketsMatching(char c1, char c2) {
	
	if(c1 == ')' && c2 == '(') return true;
	else if(c1 == ']' && c2 == '[') return true;
	else if(c1 == '}' && c2 == '{') return true;
	else return false;
}

bool isValid(char *s) {	

	struct ListNodeChar *stack;
	char *opening = "([{";
	char *closing = ")]}";
	
	listInitializeChar(&stack);
	int strLen = strlen(s);

	for(int i=0; i<strlen(s); i++) {
		for(int j=0; j<strlen(opening); j++) {	
			if(s[i] == opening[j]) 
				listPushChar(stack, s[i]);
			if(s[i] == closing[j]) {
				if(listCountChar(stack) == 0) 
					return false;
				// If brackets are not matching
				if(!bracketsMatching(s[i], listPopChar(stack))) 
					return false;
			} 
		}
	}
			
	if(listCountChar(stack) == 0)
		return true;
	else
		return false;
}

/* Test */

void testFunction(char *s, bool sol, int testNum) {
	
	bool tmp;
	double timeSpent;
	
	clock_t tic = clock();

	tmp = isValid(s);

	clock_t toc = clock();

    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);

    if(tmp == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}	

int main(void) {
	
	char *test1 = "()";
	bool sol1 = true;
	testFunction(test1, sol1, 1);	
	
	char *test2 = "()[]{}";
	bool sol2 = true;
	testFunction(test2, sol2, 2);	

	char *test3 = "(]";
	bool sol3 = false;
	testFunction(test3, sol3, 3);	
	
	return EXIT_SUCCESS;
}
