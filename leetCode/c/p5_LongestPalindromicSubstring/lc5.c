#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum PalindromeType {
    Even,
    Odd
};

struct Palindrome {
    int size;
    int leftIndex;
    int rightIndex;
    enum PalindromeType type;
};

struct Palindrome findPalindromeStats(int l, int r, char *s) {
    
    struct Palindrome pal;  
    pal.size = 0;
    pal.leftIndex = l;
    pal.rightIndex = r;
    pal.type = Odd;
     
    while(pal.leftIndex >= 0 && pal.rightIndex < strlen(s) && s[pal.leftIndex] == s[pal.rightIndex]) {
        pal.leftIndex--;
        pal.rightIndex++; 
        pal.size++;
    }

    return pal;
}

char* findPalindrome(struct Palindrome pal, char *s) {
     
    char *tmp = (char *) malloc(pal.size * sizeof(char));

    for(int i = pal.leftIndex; i <= pal.rightIndex; i++)
        tmp[i] = s[i];

    return tmp;
}

char* longestPalindrome(char *s) {
    
    struct Palindrome longestPalindrome;
    struct Palindrome tmpPalindrome;
    longestPalindrome.size = 0;
    
    for(int i=0; i<strlen(s); i++) {
        // odd case
        tmpPalindrome = findPalindromeStats(i, i, s);
        if(tmpPalindrome.size > longestPalindrome.size) 
            longestPalindrome = tmpPalindrome;                      
        // even case
        tmpPalindrome = findPalindromeStats(i, i+1, s);
        if(tmpPalindrome.size > longestPalindrome.size) {
            longestPalindrome = tmpPalindrome;
            longestPalindrome.type = Even;
        }
    }
 
    char *palindromeString = (char *) malloc(longestPalindrome.size * sizeof(char));

    palindromeString = findPalindrome(longestPalindrome, s);

    return palindromeString;
}

int main(void) {
     
    return EXIT_SUCCESS;
}
