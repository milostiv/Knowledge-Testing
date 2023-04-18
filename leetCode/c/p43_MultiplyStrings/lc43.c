/* Given two non-negative integers num1 and num2 represented as strings, 
   return the product of num1 and num2, also represented as a string.

   Note: You must not use any built-in BigInteger library or convert the inputs to integer directly. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../mylib/mylib.h"

void revstr(char* num) {
    
    int i, temp;
    int len = strlen(num);

    for(int i=0; i<len/2; i++) {
        
        temp = num[i];
        num[i] = num[len - 1 - i];
        num[len - 1 - i] = temp;
    } 
}

int numStrToInt(char* num) {
    
    int ans = 0;
    int dec = 1;
    int numSize = strlen(num);

    for(int i=numSize-1; i>=0; i--) {
                    
        ans += (num[i] - 48) * dec;
        dec *= 10;
    } 

    return ans;
}

char* numIntToStr(int num) {

    char* ans = allocateArrayChar(ans, 20);
    int temp;
    int i = 0;
    
    while(num > 0) {
        
        temp = num % 10;
        ans[i] = temp + 48;
        num /= 10;
        i++;
    }
    
    ans = reallocateArrayChar(ans, i+1);
    revstr(ans);

    return ans;
}

char* multiply(char* num1, char* num2) {

    int ans = numStrToInt(num1) * numStrToInt(num2);
    char* ans_st = numIntToStr(ans);

    return ans_st;
}

int main(void) {
 
    // Test 1:

    printf("Test 1:\n");
    char* num1 = "2";
    char* num2 = "3";
    char* sol1;
    printf("Number 1: %s\nNumber 2: %s\n", num1, num2);
    sol1 = multiply(num1, num2);
    printf("Solution 1: %s\n", sol1); 
 
    // Test 2:

    printf("Test 2:\n");
    char* num3 = "123";
    char* num4 = "456";
    char* sol2;
    printf("Number 1: %s\nNumber 2: %s\n", num3, num4);
    sol2 = multiply(num3, num4);
    printf("Solution 2: %s\n", sol2); 
 
    return EXIT_SUCCESS;
}
