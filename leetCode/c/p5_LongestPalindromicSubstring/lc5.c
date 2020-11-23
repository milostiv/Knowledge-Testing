#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Palindrome {
    int size;
    int leftIndex;
    int rightIndex;
};

struct Palindrome findPalindromeStats(int l, int r, char *s) {
    
    struct Palindrome pal;  
    pal.size = 0;
    pal.leftIndex = l;
    pal.rightIndex = r;
     
    while(pal.leftIndex >= 0 && pal.rightIndex < strlen(s) && s[pal.leftIndex] == s[pal.rightIndex]) {
        pal.leftIndex--;
        pal.rightIndex++; 
        pal.size++;
    }

    return pal;
}

char* findPalindrome(int l, int r, char *s) {
    
    struct Palindrome pal = findPalindromeStats(l, r, s);  
      
    char *tmp = (char *) malloc(pal.size * sizeof(char));

    for(int i = pal.leftIndex; i <= pal.rightIndex; i++)
        tmp[i] = s[i];

    return tmp;
}

char* longestPalindrome(char *s) {
    
    char *palindromeString = (char *) malloc(strlen(s) * sizeof(char));
    
    for(int i=0; i<strlen(s); i++) {
        // odd case
                
    }
}

int main(void) {
     
    return EXIT_SUCCESS;
}
