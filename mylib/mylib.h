#ifndef MYLIB_H
#define MYLIB_H

int** allocateMatrix(int **matrix, int rows, int coll);
int** reallocateMatrix(int **matrix, int rows, int coll);
void freeAllocatedMatrix(int **matrix, int rows);
void printArray(int *matrix, int arraySize); 
void printMatrix(int **matrix, int rows, int coll);

#endif /* MYLIB_H */
