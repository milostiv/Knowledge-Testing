/* Implement strStr(). Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../mylib/mylib.h"

int strStr(char * haystack, char * needle) {

	int count = 0;
	char ch = haystack[0];
	int haystackSize = strlen(haystack);
	int needleSize = strlen(needle);

	while(ch != '\0') {
		
		count++;
		ch = haystack[count];
	}

	return count;
}

int main(void) {

	/* Test 1: */

	printf("Test 1: \n\n");

	char *haystack1 = "hello";
	char *needle1 = "ll";

	int count = strStr(haystack1, needle1);

	printf("Count %d\n", count);
}
