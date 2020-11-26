#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int reverse(int x){

    int sol = 0, tmp = 0;
    bool neg = false;

    if(x < 0) {
        neg = true;
        x *= -1;
    }

    while(x > 0) {
        sol = sol * 10 + (x % 10);
        x /= 10; 
    }

    if(neg)
        sol *= -1;

    return sol; 
}

/* Test */

void testFunction(int x, int sol, int testNumber) {
       
    int tmp; 
    double timeSpent;
     
    clock_t tic = clock();
    
    tmp = reverse(x); 
    
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNumber);
 
    if(tmp == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {

    testFunction(123, 321, 1);    
    testFunction(-123, -321, 2);
    testFunction(120, 21, 3);
    testFunction(0, 0, 4);

    return EXIT_SUCCESS;
}
