/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. 
More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

int removeElement(int* nums, int numsSize, int val) {

	int newListSize = numsSize;
	int temp = 0;

	for(int i=0; i<newListSize; i++) {
		
		temp = i;

		if(nums[temp] == val) {
			
			while(temp < numsSize) {
				
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
	
	int nums1[4] = {3, 2, 2, 3};
	int val = 3;
	int nums1Size = sizeof(nums1) / sizeof(int);

	printf("List 1 before removing element: ");
	printArrayInt(nums1, nums1Size);

	nums1Size = removeElement(nums1, nums1Size, val);
	
	printf("List 1 after removing element: ");
	printArrayInt(nums1, nums1Size);

	/* Test 2:  */		
	
	printf("Test 2: \n\n");
	
	int nums2[8] = {0, 1, 2, 2, 3, 0, 4, 2};
	val = 2;
	int nums2Size = sizeof(nums2) / sizeof(int);

	printf("List 2 before removing element: ");
	printArrayInt(nums2, nums2Size);

	nums2Size = removeElement(nums2, nums2Size, val);
	
	printf("List 2 after removing element: ");
	printArrayInt(nums2, nums2Size);

	return EXIT_SUCCESS;
}
