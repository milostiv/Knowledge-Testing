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
 
    while(tmp.leftIndex >= 0 && tmp.rightIndex < strlen(s) && s[tmp.leftIndex] == s[tmp.rightIndex]) {
        tmp.leftIndex--;
        tmp.rightIndex++;
    }     
    tmp.leftIndex++;
    tmp.rightIndex--;  
    tmp.size = tmp.rightIndex - tmp.leftIndex + 1; 

    return tmp;
}

char* longestPalindrome(char *s) {
   
    char *pal;
    struct Palindrome longestPal = initPalindrome();
    struct Palindrome tmpPal = initPalindrome();
    
    for(int i=0; i<strlen(s); i++) {
        // odd case
        tmpPal = findPalindrome(i, i, s);  
        if(longestPal.size < tmpPal.size)
            longestPal = tmpPal; 
        // even case
        if((i+1) < strlen(s)) {
            tmpPal = findPalindrome(i, i+1, s);
            if(longestPal.size < tmpPal.size)
                longestPal = tmpPal; 
        }
    }

    pal = (char *) malloc(longestPal.size * sizeof(char));
    
    for(int i=longestPal.leftIndex; i<=longestPal.rightIndex; i++)
        pal[i-longestPal.leftIndex] = s[i]; 
    
    return pal;
}

int main(void) {
    
    char s[] = "babad"; 

    longestPalindrome(s);

    return EXIT_SUCCESS;
}
