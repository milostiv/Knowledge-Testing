#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

/* Arrays */

int** allocateMatrix(int **matrix, int rows, int coll) {
    
    matrix = (int **) malloc(rows * sizeof(int *));
    
    for(int i=0; i<rows; i++)
        matrix[i] = (int *) malloc(coll * sizeof(int)); 

    return matrix;
}

int** reallocateMatrix(int **matrix, int rows, int coll) {
    
    matrix = realloc(matrix, rows * sizeof(int *)); 
    
    for(int i=0; i<rows; i++)
        matrix[i] = (int *) realloc(matrix[i], coll * sizeof(int));  
 
    return matrix;
}

void freeAllocatedMatrix(int **matrix, int rows) {
	
	for(int i=0; i<rows; i++) {
		free(matrix[i]);
	}
	
	free(matrix);
}

void printArray(int *matrix, int arraySize) { 
    
    for(int i=0; i<arraySize; i++)
        printf("%d ", matrix[i]);

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
