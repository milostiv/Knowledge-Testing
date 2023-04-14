/* You are given an n x n 2D matrix representing an image, 
rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, 
which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

void transposeMatrix(int** matrix, int matrixSize) {

    for(int i=1; i<matrixSize; i++) {
        for(int j=0; j<i; j++) { 
            swapInt(&matrix[i][j], &matrix[j][i]);
        }
    }
}

void reverseRowsMatrix(int** matrix, int matrixSize) {

    for(int i=0; i<matrixSize; i++) {
        for(int j=0; j<matrixSize/2; j++) {
            swapInt(&matrix[i][j], &matrix[i][matrixSize - 1 - j]);
        }
    }
}

void rotateMatrix(int** matrix, int matrixSize) {

    transposeMatrix(matrix, matrixSize);
    reverseRowsMatrix(matrix, matrixSize);
}

int main(void) {
   
    // Test 1:

    printf("Test 1:\n\n");
    
    int** matrix1 = allocateMatrixInt(3, 3);

    printf("Matrix 1:\n");

    int k = 1;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix1[i][j] = k++;
        }
    }
    
    printMatrixInt(matrix1, 3, 3);   

    printf("\nRotated Matrix 1:\n");

    rotateMatrix(matrix1, 3);

    printMatrixInt(matrix1, 3, 3);   

    freeAllocatedMatrixInt(matrix1, 3);
 
    // Test 2:

    printf("\nTest 2:\n\n");

    int** matrix2 = allocateMatrixInt(4, 4); 

    printf("Matrix 2:\n");

    k = 1;
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            matrix2[i][j] = k++;
        }
    }

    printMatrixInt(matrix2, 4, 4);    
   
    printf("\nRotated Matrix 2:\n");

    rotateMatrix(matrix2, 4);

    printMatrixInt(matrix2, 4, 4);    
 
    freeAllocatedMatrixInt(matrix2, 4);

    return EXIT_SUCCESS;
}
