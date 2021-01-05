/* Given an integer, convert it to a roman numeral */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define INT_TO_ROMAN_MAP_SIZE     13
#define MAX_SIZE_OF_ROMAN_NUMERAL 20

struct Map {

    int intDigit;
    char *romanNumeral;
};

struct Map intToRomanMap[INT_TO_ROMAN_MAP_SIZE];

void initIntToRomanMap(void) {
    
    /* 1000 to M: */
    intToRomanMap[0].intDigit = 1000;
    intToRomanMap[0].romanNumeral = "M"; 
 
    /* 900 to CM: */    
    intToRomanMap[1].intDigit = 900;
    intToRomanMap[1].romanNumeral = "CM";

    /* 500 to D: */    
    intToRomanMap[2].intDigit = 500;
    intToRomanMap[2].romanNumeral = "D";

    /* 400 to CD: */
    intToRomanMap[3].intDigit = 400;
    intToRomanMap[3].romanNumeral = "CD";    
 
    /* 100 to C: */
    intToRomanMap[4].intDigit = 100;
    intToRomanMap[4].romanNumeral = "C";

    /* 90 to XC: */
    intToRomanMap[5].intDigit = 90;
    intToRomanMap[5].romanNumeral = "XC";

    /* 50 to L: */
    intToRomanMap[6].intDigit = 50;
    intToRomanMap[6].romanNumeral = "L";
 
    /* 40 to XL: */
    intToRomanMap[7].intDigit = 40;
    intToRomanMap[7].romanNumeral = "XL";

    /* 10 to X: */
    intToRomanMap[8].intDigit = 10;
    intToRomanMap[8].romanNumeral = "X";

    /* 9 to IX: */
    intToRomanMap[9].intDigit = 9;
    intToRomanMap[9].romanNumeral = "IX";

    /* 5 to V: */
    intToRomanMap[10].intDigit = 5;
    intToRomanMap[10].romanNumeral = "V";

    /* 4 to IV: */
    intToRomanMap[11].intDigit = 4;
    intToRomanMap[11].romanNumeral = "IV";

    /* 1 to I: */
    intToRomanMap[12].intDigit = 1;
    intToRomanMap[12].romanNumeral = "I";
}

char *intToRoman(int num) {
    
    char *romanNum = (char *) malloc(MAX_SIZE_OF_ROMAN_NUMERAL * sizeof(char));
 
    for(int i=0; i<INT_TO_ROMAN_MAP_SIZE; i++) {
        
        while(intToRomanMap[i].intDigit <= num) {
            
            strncat(romanNum, intToRomanMap[i].romanNumeral, strlen(intToRomanMap[i].romanNumeral));
            num -= intToRomanMap[i].intDigit;
        }    
    }

    return romanNum;
} 

/* Test */

void testFunction(int num, char *sol, int testNum) {

    double timeSpent;

    clock_t tic = clock();
 
    intToRoman(num);
 
    clock_t toc = clock(); 
    
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
 
    printf("\nTEST%d: ", testNum);
     
    if(strcmp(intToRoman(num), sol) == 0) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {

    initIntToRomanMap();
    
    // Test 1:
   
    int num = 3;
    char *sol1 = "III";   
 
    testFunction(num, sol1, 1); 
    
    // Test 2:

    num = 4;
    char *sol2 = "IV";   
 
    testFunction(num, sol2, 2); 
   
    // Test 3:
 
    num = 9;
    char *sol3 = "IX";   
 
    testFunction(num, sol3, 3); 
   
    // Test 4:
 
    num = 58;
    char *sol4 = "LVIII";   
 
    testFunction(num, sol4, 4); 

    // Test 5:
 
    num = 1994;
    char *sol5 = "MCMXCIV";

    testFunction(num, sol5, 5); 

    return EXIT_SUCCESS;
}
