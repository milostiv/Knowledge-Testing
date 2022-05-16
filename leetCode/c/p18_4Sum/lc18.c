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

	int sum = 0, currRow = 0;
		
	if(numsSize < 4) {
		*returnColumnSizes = NULL;
		*returnSize = 0;
		return NULL;	
	}

	sortArray(nums, numsSize);

	int** answer;

	for(int i=0; i<numsSize-3; i++) {
	
		if(i>0 && nums[i]==nums[i-1])
			continue;

		for(int j=i+1; j<numsSize-2; j++) {
			for(int k = j+1; k<numsSize-1; k++) {
				for(int l = k+1; l<numsSize; l++) {
					
					sum = nums[i] + nums[j] + nums[k] + nums[l];

					if(sum == target) {
						
						currRow++;
						
						if(currRow == 1)
							answer = allocateMatrix(currRow, COLUMN_SIZE);
						else 
							reallocateMatrix(answer, currRow, COLUMN_SIZE);

						answer[currRow-1][0] = nums[i];
						answer[currRow-1][1] = nums[j];
						answer[currRow-1][2] = nums[k];	
						answer[currRow-1][3] = nums[l];
					}
				}
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

	int** answer = allocateMatrixInt(answer, 3, COLUMN_SIZE);
	answer = fourSum(nums1, numsSize, target1, returnSize, returnColumnSizes);

	for(int i=0; i<*returnSize; i++) {
		for(int j=0; j<COLUMN_SIZE; j++) {

			printf("%d ", answer[i][j]);
		}	
		printf("\n");
	}

	printf("\nNot yet finished!\n\n");
	
	return EXIT_SUCCESS;
}
