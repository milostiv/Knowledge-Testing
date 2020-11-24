#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Palindrome {
    int size;
    int leftIndex;
    int rightIndex;
};

void printPalindromeInfo(struct Palindrome pal) {
    
    printf("Palindrome:\nSize: %d\nLeft index:%d\nRight index:%d\n", pal.size, pal.leftIndex, pal.rightIndex);
}

char* longestPalindrome(char *s) {
    
}

int main(void) {
    
    char s[] = "babad"; 
 
    return EXIT_SUCCESS;
}
