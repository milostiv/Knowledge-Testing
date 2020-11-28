/* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* convert(char *s, int numRows){

    int cycle = 2 * numRows - 2;
    int k;
    int currentCharPos = 0;
    char *res = (char *) malloc(strlen(s) * sizeof(char));

    if(numRows == 1 || numRows >= strlen(s))
        return s;
    
    for(int i=0; i<numRows; i++) {
        for(int j=i; j<strlen(s); j+=cycle) {
            res[currentCharPos++] = s[j];
            k = j + cycle - (2 * i);
            if(i != 0 && i != (numRows - 1) && k < strlen(s)) 
                res[currentCharPos++] = s[k]; 
        }
    }    

    return res;
}

/* Test */

void testFunction(char *s, int numRows, char *sol, int testNum) {
        
    char *tmp; 
    double timeSpent;

    clock_t tic = clock();
 
    tmp = convert(s, numRows);
  
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
 
    if(!strcmp(tmp, sol)) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {
    
    char s1[] = "PAYPALISHIRING";
    char sol1[] = "PAHNAPLSIIGYIR";
    int numRows = 3;

    testFunction(s1, numRows, sol1, 1);

    char sol2[] = "PINALSIGYAHRPI";
    numRows = 4;
    
    testFunction(s1, numRows, sol2, 2);

    char s2[] = "A";
    char sol3[] = "A";
    numRows = 1;
    
    testFunction(s2, numRows, sol3, 3);
 
    return EXIT_SUCCESS;
}
