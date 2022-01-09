#ifndef MYLIB_H
#define MYLIB_H

/* ---------------------------- Mathematics ---------------------------- */

int powInt(int base, unsigned int pow);

/* --------------------------------------------------------------------- */

/* -------------------------- Arrays (2D, 3D) -------------------------- */

/* Char: */

char* allocateArrayChar(char *array, int size);
char* reallocateArrayChar(char *array, int size);
void printArrayChar(char *array, int arraySize);
char** allocateMatrixChar(char **matrix, int rows, int coll);
char** reallocateMatrixChar(char **matrix, int rows, int coll);
void freeAllocatedMatrixChar(char **matrix, int rows);
void printMatrixChar(char **matrix, int rows, int coll);

/* Int: */

int* allocateArrayInt(int *array, int size);
int* reallocateArrayInt(int *array, int size);
void printArrayInt(int *array, int arraySize);
int** allocateMatrixInt(int **matrix, int rows, int coll);
int** reallocateMatrixInt(int **matrix, int rows, int coll);
void freeAllocatedMatrixInt(int **matrix, int rows);
void printMatrixInt(int **matrix, int rows, int coll);

/* --------------------------------------------------------------------- */

/* ---------------------------- Linked List ---------------------------- */

struct ListNode {
    int val;
    struct ListNode *next;
};

void listInitialize(struct ListNode **list);
void listInsertSingle(struct ListNode *list, int val);
void listInsertArray(struct ListNode *list, int *array, int arraySize);
void listPrint(struct ListNode *list);
void listFree(struct ListNode *list);

/* --------------------------------------------------------------------- */

#endif /* MYLIB_H */
