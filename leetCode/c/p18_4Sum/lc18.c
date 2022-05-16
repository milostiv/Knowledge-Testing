/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "../../../mylib/mylib.h"

#define COLUMN_SIZE 4

void sortArray(int *array, int arraySize) {
	
	int temp;

	for(int i=0; i<arraySize-1; i++) {
		for(int j=i+1; j<arraySize; j++) {
			if(array[i] > array[j]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}	
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {

	int sum = 0, currRow = 0, l, r;
		
	if(numsSize < 4) {
		*returnColumnSizes = NULL;
		*returnSize = 0;
		return NULL;	
	}

	sortArray(nums, numsSize);

	//for(int i=0; i<numsSize; i++) {
	//	printf("%d ", nums[i]);
	//}
	//printf("\n");

	int** answer;

	for(int i=0; i<numsSize-3; i++) {
	
		if(i>0 && nums[i]==nums[i-1])
			continue;

		if(nums[i]*4 > target)
			break;

		for(int j=i+1; j<numsSize-2; j++) {
			
			if(j>i+1 && nums[j]==nums[j+1])
				continue;	

			l = j+1;
			r = numsSize-1;

			while(l<r) {
				
				sum = nums[i] + nums[j] + nums[l] + nums[r];
		
				if(sum == target) {
				
					currRow++;

					if(currRow == 1) 
						answer = allocateMatrixInt(answer, 1, COLUMN_SIZE);
					else 
						answer = reallocateMatrixInt(answer, currRow, COLUMN_SIZE);

			//		answer[currRow][0] = nums[i];		
			//		answer[currRow][0] = nums[j];	
			//		answer[currRow][0] = nums[l];
			//		answer[currRow][0] = nums[r];

			//		while(l<r && nums[l] == nums[l+1]) 
			//			l++;

			//		while(l<r && nums[r] == nums[r-1])
			//			r--;

					l++;
					r--;
				}
	
				else if(sum > target)
					r--;					

				else 
					l++;	
			}

		}
	}
	
	*returnSize = currRow;
	
	return answer;
	
}

int main(void) {

	// Test
	int nums1[6] = {1,0,-1,0,-2,2};
	int target1 = 0;
	int* returnSize;
	int** returnColumnSizes;
	
	int numsSize = sizeof(nums1)/sizeof(int);

	fourSum(nums1, numsSize, target1, returnSize, returnColumnSizes);

	printf("\nNot yet finished!\n\n");
	
	return EXIT_SUCCESS;
}
