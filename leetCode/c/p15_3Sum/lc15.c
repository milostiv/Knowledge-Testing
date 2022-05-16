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

#define COLUMN_SIZE 3
#define TARGET 0

int* sortArray(int *array, int arraySize) {
	
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

	return array;
}

int** threeSum(int *nums, int numsSize, int* returnSize, int** returnColumnSizes) {	
	
    int currRow = 0;	
    int **answer = allocateMatrixInt(currRow + 1, COLUMN_SIZE);

	nums = sortArray(nums, numsSize);

    for(int i=0; i<numsSize-2; i++) {
		if(i>0 && nums[i] == nums[i-1]) {
			continue;
		}
        for(int j=i+1; j<numsSize-1; j++) {
            for(int k=j+1; k<numsSize; k++) {
                if(nums[i] + nums[j] + nums[k] == TARGET) {
		    		if(currRow > 0) 
            			reallocateMatrixInt(answer, currRow + 1, COLUMN_SIZE);	
		    		answer[currRow][0] = nums[i];
                    answer[currRow][1] = nums[j];
                    answer[currRow][2] = nums[k];
                    currRow++;
                }                
            } 
        }
    }

    *returnSize = currRow - 1;
    
    return answer; 
}

int main(void) {
 
	int nums[6] = {-1,0,1,2,-1,-4}; 
    int numsSize = sizeof(nums) / sizeof(int);
	int *returnSize;
	int **returnColumnSize;

	int **matrix = allocateMatrixInt(2, 3);
	
	matrix = threeSum(nums, numsSize, returnSize, returnColumnSize);

	printMatrixInt(matrix, 2, 3);

	freeAllocatedMatrixInt(matrix, 2);

    return EXIT_SUCCESS;
}
