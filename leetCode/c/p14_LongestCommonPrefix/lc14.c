/* Write a function to find the longest common prefix string amongst an array of strings. If there is no common prefix, return an empty string "" */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char * longestCommonPrefix(char ** strs, int strsSize){
 
}

char * longestPrefixBetweenTwoStrings(char * str1, char * str2){
    
    int i = 0;
    char * str = (char *) malloc(strlen(str1) * sizeof(char));
    
    while(i < strlen(str1) && i < strlen(str2)){
        if(str1[i] != str2[i])
            break;

        str[i] = str1[i];  
        i++;              
    }      

    str = realloc(str, i);    

    return str;
}

// Test

int main(void){
    
    return EXIT_SUCCESS;
}
