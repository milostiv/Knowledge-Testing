/* Given a roman numeral, convert it to an integer */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int romanNumeralsMap(char *s) {
    
    switch(s[0]) {
        
        case 'I': 
            if(s[1] == 'V')
                return 4;
            else if(s[1] == 'X')
                return 9;    
            else 
                return 1;
        case 'V':
            return 5;
        case 'X': 
            if(s[1] == 'L')
                return 40;
            else if(s[1] == 'C')
                return 90;
            else
                return 10;
        case 'L':
            return 50;
        case 'C':
            if(s[1] == 'D')
                return 400;
            else if(s[1] == 'M')
                return 900;
            else
                return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:    
            return 0;
    }
}

int romanToInt(char *s) {
   
    int num = 0;
    char *currNumeral = (char *) malloc(2 * sizeof(char));
    char *temp = (char *) malloc(1);
 
    for(int i=0; i<strlen(s); i++) {
        
        currNumeral[0] = s[i];
        
        if((currNumeral[0] == 'I' || currNumeral[0] == 'X' || currNumeral[0] == 'C') && i+1 < strlen(s)) {
            
            temp[0] = s[i+1];
            
            if(romanNumeralsMap(temp) > romanNumeralsMap(currNumeral)) {
            
                currNumeral[1] = s[i+1];
                i++; 
            }
        }
 
        num += romanNumeralsMap(currNumeral);
    }
    
    return num;
}

/* Test */

void testFunction(char *romNum, int sol, int testNum) {

    double timeSpent;

    clock_t tic = clock();
 
    int num = romanToInt(romNum);
 
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
     
    if(num == sol) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {
    
    // Test 1:
   
    char *romNum1 = "III";   
    int sol = 3;
 
    testFunction(romNum1, sol, 1); 
    
    // Test 2:

    char *romNum2 = "IV";   
    sol = 4;
 
    testFunction(romNum2, sol, 2); 
   
    // Test 3:
 
    char *romNum3 = "IX";    
    sol = 9;
 
    testFunction(romNum3, sol, 3); 
   
    // Test 4:
 
    char *romNum4 = "LVIII";   
    sol = 58;
 
    testFunction(romNum4, sol, 4); 

    // Test 5:
 
    char *romNum5 = "MCMXCIV";
    sol = 1994;

    testFunction(romNum5, sol, 5); 

    return EXIT_SUCCESS;
}
