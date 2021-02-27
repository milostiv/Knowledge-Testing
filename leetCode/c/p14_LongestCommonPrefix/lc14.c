/* Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR_SIZE 10

char * longestPrefixBetweenTwoStrings(char * str1, char * str2){
    
    int i = 0;
    char * str = (char *) malloc(strlen(str1) * sizeof(char));
    
    while(i < strlen(str1) && i < strlen(str2)){
        if(str1[i] != str2[i])
            break;

        str[i] = str1[i];  
        i++;              
    }      

    if(i != 0)
        str = realloc(str, i);    

    return str;
}

char * longestCommonPrefix(char ** strs, int strsSize){

    char * prefix = strs[0];
    
    for(int i = 1; i < strsSize; i++){
        prefix = longestPrefixBetweenTwoStrings(prefix, strs[i]);
    }

    return prefix;
}

// Test

void testFunction(char ** strs, int strsSize, char * sol, int testNum) {

    double timeSpent;

    clock_t tic = clock();
 
    char * str = longestCommonPrefix(strs, strsSize);
 
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
     
    if(!strcmp(str, sol))
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void){

    char * strs1[3][MAX_STR_SIZE] = {
        "flower",
        "flow",
        "flight" 
    };

    char * strs2[3][MAX_STR_SIZE] = {
        "dog",
        "racecar",
        "car"
    };

    testFunction(*strs1, 3, "fl", 1); 
    testFunction(*strs2, 3, "", 2);
    
    return EXIT_SUCCESS;
}
