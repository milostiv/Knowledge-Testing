/**
* Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
*
* A mapping of digit to letters is just like on the telephone buttons. Note that 1 does not map to any letters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void freeAllocatedMatrix(int **array, int rows, int coll) {
	
	for(int i=0; i<coll; i++) {
		free(array[i]);
	}
	
	free(array);
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

char** recursive_search(int pos, char* digits) {

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
		
}

int main(void) {
	
	char digits[2] = "23";
	int digits_sz = sizeof(digits)/sizeof(char);
	int *return_size;

	return EXIT_SUCCESS;
}
