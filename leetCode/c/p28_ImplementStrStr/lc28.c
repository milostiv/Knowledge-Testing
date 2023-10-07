/* Implement strStr(). Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"

#define NEEDLE_NOT_IN_HAYSTACK -1;

int strStr(char * haystack, char * needle) {

	int i, j;
	int haystack_size = strlen(haystack);
	int needle_size = strlen(needle);

	for(i=0; i<haystack_size - needle_size + 1; i++) {
	
		for(j=0; j<needle_size; j++) {
		
			if(haystack[i+j] != needle[j]) 
				break;			
		}	

		if(j == needle_size)
			return i;
	}

	return NEEDLE_NOT_IN_HAYSTACK;
}

int main(void) {

	/* Test 1: */

	printf("Test 1: \n\n");

	char *haystack1 = "hello";
	char *needle1 = "ll";

	printf("Haystack: %s\n", haystack1);
	printf("Needle: %s\n\n", needle1);

	int sol = strStr(haystack1, needle1);

	printf("Test 1 solution: %d\n\n", sol);
	
	/* Test 2: */

	printf("Test 2: \n\n");

	char *haystack2 = "aaaaa";
	char *needle2 = "bba";

	printf("Haystack: %s\n", haystack2);
	printf("Needle: %s\n\n", needle2);

	sol = strStr(haystack2, needle2);

	printf("Test 2 solution: %d\n", sol);

	return EXIT_SUCCESS;
}
