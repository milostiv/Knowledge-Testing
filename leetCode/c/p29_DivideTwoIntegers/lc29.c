/* Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. 
For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
Return the quotient after dividing dividend by divisor. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

int divide(int dividend, int divisor) {

	int quotient = 0;
	int temp_divisor = 0;
	int sign = 1;
	bool bothPositive = (divisor > 0 && dividend > 0);
	bool bothNegative = (divisor < 0 && dividend < 0);

	if(abs(divisor) > abs(dividend)) 
		return 0;	

	if((bothPositive || bothNegative) != true) {
	
		bothNegative = true;
		sign = -1;
	}

	while(abs(temp_divisor) < abs(dividend)) {
	   
	   if(bothPositive) 
	   	temp_divisor += divisor;	
	
	   if(bothNegative) 
	   	temp_divisor -= divisor;
	   
	   quotient++;		
	}

	return (quotient-1) * sign;
}

int main(void) {

	/* Test 1: */
	
	int dividend1 = 10;
	int divisor1 = 3;

	int quotient1 = divide(dividend1, divisor1);

	printf("Test 1 quotient: %d\n", quotient1);

	/* Test 2: */
	
	int dividend2 = 7;
	int divisor2 = -3;

	int quotient2 = divide(dividend2, divisor2);

	printf("Test 2 quotient: %d\n", quotient2);
	
	return EXIT_SUCCESS;
}
