#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Palindrome {
    int size;
    int leftIndex;
    int rightIndex;
};

struct Palindrome initPalindrome(void) {
    
    struct Palindrome pal; 
     
    pal.leftIndex = 0;
    pal.rightIndex = 0;
    pal.size = 0;

    return pal;    
}

void printPalindromeInfo(struct Palindrome pal, char *s) {
    
    printf("%s palindrome:\nSize: %d\nLeft index:%d\nRight index:%d\n\n\n", s, pal.size, pal.leftIndex, pal.rightIndex);
}

struct Palindrome findPalindrome(int l, int r, char *s) {
    
    struct Palindrome tmp = initPalindrome();
    tmp.leftIndex = l;
    tmp.rightIndex = r;
    int num = 1;
 
    if(l == r) { // odd case 
        while(tmp.leftIndex >= 0 && tmp.rightIndex < strlen(s) && s[tmp.leftIndex] == s[tmp.rightIndex]) {
            tmp.leftIndex--;
            tmp.rightIndex++;
        }     
        tmp.leftIndex++;
        tmp.rightIndex--;  
        tmp.size = tmp.rightIndex - tmp.leftIndex + 1; 
    }
    else { // even case
        
    } 

    return tmp;
}

char* longestPalindrome(char *s) {
    
}

int main(void) {
    
    char s[] = "babad"; 
    struct Palindrome longestPalindrome = initPalindrome();
    struct Palindrome tmpPalindrome = initPalindrome();
    
    for(int i=0; i<strlen(s); i++) {
        tmpPalindrome = findPalindrome(i, i, s);  
        if(longestPalindrome.size < tmpPalindrome.size)
            longestPalindrome = tmpPalindrome; 
    }

    printPalindromeInfo(longestPalindrome, "Longest");

    return EXIT_SUCCESS;
}
