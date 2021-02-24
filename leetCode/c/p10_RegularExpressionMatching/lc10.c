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
    
    // Initialize array with false values (because setting dp[0][0] to {0} did not work)
    memset(dp, false, sizeof dp); 
 
    // Match if both string and pattern are empty
    dp[0][0] = true;

    // For patterns with *
    for(int i = 2; i < columns + 1; i++){
        if(p[i - 1] == '*')
            dp[0][i] = dp[0][i - 2];
    }

    // For remaining characters    
    for(int i = 1; i < rows + 1; i++){
        for(int j = 1; j < columns + 1; j++){
            if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                dp[i][j] = dp[i - 1][j - 1];
            else if(j > 1 && p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2];
                if(p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
        }
    }       

    return dp[rows][columns];
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

    char s1[] = "aa";
    char p1[] = "a";

    testFunction(s1, p1, false, 1);

    char s2[] = "aa";
    char p2[] = "a*";
    
    testFunction(s2, p2, true, 2);

    char s3[] = "ab";
    char p3[] = ".*";
    
    testFunction(s3, p3, true, 3);

    char s4[] = "aab";
    char p4[] = "c*a*b";
    
    testFunction(s4, p4, true, 4);

    char s5[] = "mississippi";
    char p5[] = "mis*is*p*.";
    
    testFunction(s5, p5, false, 5);
     
    return EXIT_SUCCESS;
}
