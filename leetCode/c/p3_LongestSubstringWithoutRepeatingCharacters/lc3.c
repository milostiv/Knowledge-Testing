/* Given a string s, find the length of the longest substring without repeating characters. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int lengthOfLongestSubstring(char * s) {

    int stringSize = strlen(s); 
    int substring[127]; // Number of characters in ASCII table (not including extended set of characters)   
    int currSubstringStart = 0;
    int currLength = 0;
    int longest = 0;

    memset(substring, -1, sizeof(substring)); // Set all array values to -1
    
    for(int i=0; i<stringSize; i++) {
        if(substring[s[i]] >= currSubstringStart) {
            currSubstringStart = substring[s[i]] + 1; 
            currLength = i - substring[s[i]];
            substring[s[i]] = i; 
        } 
        else {
            substring[s[i]] = i;
            currLength++;
            if(currLength > longest)
                longest = currLength;
        }
    }        
    
    return longest;
}

/* Test */

void testFunction(char *s, int solution, int testNumber) {
   
    int temp;
    double timeSpent;

    clock_t tic = clock();
    
    temp = lengthOfLongestSubstring(s); 
    
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNumber);

    if(temp == solution) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {
   
    char str1[] = "abcabcbb"; 
    char str2[] = "bbbbb"; 
    char str3[] = "pwwkew";
    char str4[] = "";
    
    testFunction(str1, 3, 1);
    testFunction(str2, 1, 2);
    testFunction(str3, 3, 3);
    testFunction(str4, 0, 4);
    
    return EXIT_SUCCESS;
}
