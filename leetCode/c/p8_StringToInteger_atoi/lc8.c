/* Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this 
character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this 
function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or 
it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int myAtoi(char *s){
    
    char c; 
    int sign = 1, n = 0, digit = 0;
    bool firstDigit = false;
     
    for(int i=0; i<strlen(s); i++) {
        
        if(!firstDigit) { 
            // discard white characters 
            while(s[i] == ' ' && (i+1) < strlen(s))
                i++;

            // check for sign    
            if((c = s[i]) == '-' && (i+1) < strlen(s)) {
                sign = -1;
                i++;
            }
        }
 
        // get next digit  
        if(s[i] >= '0' && s[i] <= '9') {
            digit = s[i] - '0';
            firstDigit = true;
        }
        else break;

        n = n * 10 + digit;                    
    }

    n *= sign; 
    
    return n;
}

/* Test */

void testFunction(char *s, int sol, int testNum) {

    int n;
    double timeSpent;

    clock_t tic = clock();
 
    n = myAtoi(s);
  
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
 
    if(n == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {
   
    char s1[] = "42"; 
    char s2[] = "   -42";
    char s3[] = "4193 with words";
    
    testFunction(s1, 42, 1);
    testFunction(s2, -42, 2);
    testFunction(s3, 4193, 3);
     
    return EXIT_SUCCESS;
}
