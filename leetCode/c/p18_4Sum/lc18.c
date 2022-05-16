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

int** allocateMatrix(int rows, int cols) {
    int** m = malloc(rows * sizeof(double*));
    if(!m) 
		return NULL;

    m[0] = malloc(rows * cols * sizeof(double));
    if (!m[0]) {
        free(m);
        return NULL;
    }

    for(int r = 1; r < rows; r++) {
        m[r] = m[r-1]+cols;
    }

    return m; 
}

void freeAllocatedMatrix(int** m) {
    if(m) 
		free(m[0]);
    free(m);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
	
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

	int** answer = allocateMatrix(1, COLUMN_SIZE);
	freeAllocatedMatrix(answer);

	return NULL;
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
