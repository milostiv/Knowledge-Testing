/* Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int flipNumber(int x) {
   
    int sol = 0;
 
    while(x != 0) {
        sol = sol * 10 + (x % 10);
        x /= 10;
    }
    
    return sol;  
}

bool isPalindrome(int x){
    
    if((x != 0 && x % 10 == 0) || x < 0) 
        return false;

    if(x == flipNumber(x)) 
        return true;
    else 
        return false;
}

/* Test */

void testFunction(int x, bool sol, int testNum) {
    
    bool tmp;
    double timeSpent;

    clock_t tic = clock();
 
    tmp = isPalindrome(x);
  
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
 
    if(tmp == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}
 
int main(void) {
    
    testFunction(121, true, 1);
    testFunction(-121, false, 2);
    testFunction(10, false, 3);
    testFunction(-101, false, 4);

    return EXIT_SUCCESS;
}
