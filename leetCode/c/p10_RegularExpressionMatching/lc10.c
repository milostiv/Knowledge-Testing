/* Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial). */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

bool isMatch(char * s, char * p){

}

/* Test */

void testFunction(char * s, char * p, bool sol, int testNum){
    
    bool tmp;
    double timeSpent;

    clock_t tic = clock();
 
    tmp = isMatch(s, p);
  
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
 
    if(tmp == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void){
     
    return EXIT_SUCCESS;
}
