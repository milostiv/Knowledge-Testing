#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

/* Function implemented in mylib.c/h as myPowDouble */

int main(void) {

	/* Test 1 */
	
	double x1 = 2.0;
	int n1 = 10;

	printf("Test1:\n%f\n\n", myPowDouble(x1, n1));

	/* Test 2 */
	
	double x2 = 2.1;
	int n2 = 3;

	printf("Test2:\n%f\n\n", myPowDouble(x2, n2));

	/* Test 3 */
	
	double x3 = 2.0;
	int n3 = -2;

	printf("Test3:\n%f\n", myPowDouble(x3, n3));
				
	return EXIT_SUCCESS;
}
