#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

/* -------------------------- Arrays (2D, 3D) -------------------------- */

/* Char: */

char* allocateArrayChar(char *array, int size) {
	
	array = (char *) malloc(size * sizeof(char));

	return array;
}

char* reallocateArrayChar(char *array, int size) {
	
	array = realloc(array, size * sizeof(char));

	return array;
}

void printArrayChar(char *array, int arraySize) { //TODO: Switch to void?
    
    for(int i=0; i<arraySize; i++)
        printf("%d ", array[i]);

    printf("\n");
}

char** allocateMatrixChar(char **matrix, int rows, int coll) {
    
    matrix = (char **) malloc(rows * sizeof(char *));
    
    for(int i=0; i<rows; i++)
        matrix[i] = (char *) malloc(coll * sizeof(char)); 

    return matrix;
}

char** reallocateMatrixChar(char **matrix, int rows, int coll) {
    
    matrix = realloc(matrix, rows * sizeof(char *)); 
    
    for(int i=0; i<rows; i++)
        matrix[i] = (char *) realloc(matrix[i], coll * sizeof(char));  
 
    return matrix;
}

void freeAllocatedMatrixChar(char **matrix, int rows) { //TODO: Switch to void?
	
	for(int i=0; i<rows; i++) {
		free(matrix[i]);
	}
	
	free(matrix);
}

void printMatrixChar(char **matrix, int rows, int coll) { //TODO: Switch to void?

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

/* Int: */

int* allocateArrayInt(int *array, int size) {
	
	array = (int *) malloc(size * sizeof(int));

	return array;
}

int* reallocateArrayInt(int *array, int size) {
	
	array = realloc(array, size * sizeof(int));

	return array;
}

void printArrayInt(int *array, int arraySize) { //TODO: Switch to void?
    
    for(int i=0; i<arraySize; i++)
        printf("%d ", array[i]);

    printf("\n");
}

int** allocateMatrixInt(int **matrix, int rows, int coll) {
    
    matrix = (int **) malloc(rows * sizeof(int *));
    
    for(int i=0; i<rows; i++)
        matrix[i] = (int *) malloc(coll * sizeof(int)); 

    return matrix;
}

int** reallocateMatrixInt(int **matrix, int rows, int coll) {
    
    matrix = realloc(matrix, rows * sizeof(int *)); 
    
    for(int i=0; i<rows; i++)
        matrix[i] = (int *) realloc(matrix[i], coll * sizeof(int));  
 
    return matrix;
}

void freeAllocatedMatrixInt(int **matrix, int rows) { //TODO: Switch to void?
	
	for(int i=0; i<rows; i++) {
		free(matrix[i]);
	}
	
	free(matrix);
}

void printMatrixInt(int **matrix, int rows, int coll) { //TODO: Switch to void?

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
