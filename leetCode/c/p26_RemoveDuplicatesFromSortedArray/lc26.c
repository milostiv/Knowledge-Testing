/* Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

void printList(int* nums, int numsSize) {
	
	for(int i=0; i<numsSize; i++) {
	
		printf("%d ", nums[i]);	
	}	

	printf("\n");
}

int removeDuplicates(int* nums, int numsSize) {

	int newListSize = numsSize;
	int temp = 0;

	for(int i=0; i<newListSize-1; i++) {

		temp = i;

		if(nums[temp] == nums[temp+1]) {
			
			while(temp < numsSize-1) {	
				
				nums[temp] = nums[temp+1];
				temp++;	
			}

			newListSize--;	
			i--;
		}		
	}

	return newListSize;
}

int main(void) {

	/* Test 1:  */		
	
	printf("Test 1: \n\n");
	
	int nums1[3] = {1, 1, 2};
	int nums1Size = sizeof(nums1) / sizeof(int);

	printf("List 1 before removing duplicates: ");
	printList(nums1, nums1Size);

	nums1Size = removeDuplicates(nums1, nums1Size);
	
	printf("List 1 after removing duplicates: ");
	printList(nums1, nums1Size);	

	/* Test 2: */

	printf("\nTest 2: \n\n");

	int nums2[10] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	int nums2Size = sizeof(nums2) / sizeof(int);

	printf("List 2 before removing duplicates: ");
	printList(nums2, nums2Size);

	nums2Size = removeDuplicates(nums2, nums2Size);
	
	printf("List 2 after removing duplicates: ");
	printList(nums2, nums2Size);	

	return EXIT_SUCCESS;
}
