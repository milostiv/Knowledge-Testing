/* Given a 2D integer array matrix, return the transpose of matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, 
switching the matrix's row and column indices. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

void transposeMatrix(int** matrix, int row, int col, int** sol) {

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) { 
            sol[j][i] = matrix[i][j]; 
        }
    }
}

int main(void) {
    
    // Test 1:
    
    printf("Test 1:\n\n"); 
    
    int** matrix1 = allocateMatrixInt(3, 3);
    int** sol1 = allocateMatrixInt(3, 3);

    printf("Matrix 1:\n");

    int k = 1;

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            matrix1[i][j] = k++;
        }
    }

    printMatrixInt(matrix1, 3, 3);   

    printf("\nTransposed matrix 1:\n");

    transposeMatrix(matrix1, 3, 3, sol1);

    printMatrixInt(sol1, 3, 3);

    freeAllocatedMatrixInt(matrix1, 3);
    freeAllocatedMatrixInt(sol1, 3);

    // Test 2:

    printf("\nTest 2:\n\n");

    int** matrix2 = allocateMatrixInt(2, 3);
    int** sol2 = allocateMatrixInt(3, 2);
    
    printf("Matrix 2:\n");

    k = 1;

    for(int i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            matrix2[i][j] = k++;
        }
    }

    printMatrixInt(matrix2, 2, 3);   

    printf("\nTransposed matrix 2:\n");

    transposeMatrix(matrix2, 2, 3, sol2); 

    printMatrixInt(sol2, 3, 2);

    freeAllocatedMatrixInt(matrix2, 2);
    freeAllocatedMatrixInt(sol2, 3);
    
    return EXIT_SUCCESS;
}
