/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define COLUMN_SIZE 3
#define TARGET 0

int** allocateMatrix(int **array, int rows, int coll) {
    
    array = (int **) malloc(rows * sizeof(int *));
    
    for(int i=0; i<coll; i++)
        array[i] = (int *) malloc(coll * sizeof(int)); 

    return array;
}

int** reallocateMatrix(int **array, int rows, int coll) {
    
    array = realloc(array, rows * sizeof(int *)); 
    
    for(int i=0; i<coll; i++)
        array[i] = (int *) realloc(array[i], coll * sizeof(int));  
 
    return array;
}

void printArray(int *array, int arraySize) { 
    
    for(int i=0; i<arraySize; i++)
        printf("%d ", array[i]);

    printf("\n");
}

void printMatrix(int **matrix, int rows, int coll) {

	if(rows < 1) {
		printf("[]");
		return;
	}
 
    for(int i=0; i<rows; i++) {
        for(int j=0; j<coll; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int** threeSum(int *nums, int numsSize, int* returnSize, int** returnColumnSizes) {	
	
    int currRow = 0;	
    int **answer = allocateMatrix(answer, currRow + 1, COLUMN_SIZE);

    for(int i=0; i<numsSize-2; i++) {
        for(int j=i+1; j<numsSize-1; j++) {
            for(int k=j+1; k<numsSize; k++) {
                if(nums[i] + nums[j] + nums[k] == TARGET) {
		    if(currRow > 0) {
                        answer = reallocateMatrix(answer, currRow + 1, COLUMN_SIZE);
		    }
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

	int **matrix = allocateMatrix(matrix, 2, 3);
	
	matrix = threeSum(nums, numsSize, returnSize, returnColumnSize);

	printMatrix(matrix, 2, 3);

    return EXIT_SUCCESS;
}
