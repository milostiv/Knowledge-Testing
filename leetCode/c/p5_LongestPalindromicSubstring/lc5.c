#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int findPalindromeSize(int l, int r, char *s) {
    
    int palindromeLength = 0;
     
    while(l >= 0 && r < strlen(s) && s[l] == s[r]) {
        l--;
        r++;
        palindromeLength++;
    }

    return palindromeLength;
}

char* findPalindrome(int l, int r, char *s) {
    
    int palindromeLength = 0;
     
    while(l >= 0 && r < strlen(s) && s[l] == s[r]) {
        l--;
        r++;
        palindromeLength++;
    }
     
    char *tmp = (char *) malloc(palindromeLength * sizeof(char));

    for(int i=l; i<=r; i++)
        tmp[i] = s[i];

    return tmp;
}

char* longestPalindrome(char *s) {


}

int main(void) {
     
    return EXIT_SUCCESS;
}
