/* Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*' where: 

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial). */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool isMatch(char * s, char * p){
    int rows = strlen(s);
    int columns = strlen(p);     
   
    // Both strings empty
    if(rows == 0 && columns == 0)
        return true;     

    // Patern empty
    if(columns == 0) 
        return false;

    bool dp[rows + 1][columns + 1];
    
    // Initialize array with false values
    memset(dp, false, sizeof dp);

    for(int i=0; i<rows+1; i++) {
        for(int j=0; j<columns+1; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
     
    //printf("%d, %d", rows, columns);
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

    char s[] = "aa";
    char p[] = "a";

    isMatch(s, p);
     
    return EXIT_SUCCESS;
}
