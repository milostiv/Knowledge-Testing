#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

/* ---------------------------- Mathematics ---------------------------- */

int powInt(int base, unsigned int pow) {
	
	if(pow == 0)
		return 1;
	else if (pow % 2 == 0)
        return powInt(base, pow / 2) * powInt(base, pow / 2);
    else
        return base * powInt(base, pow / 2) * powInt(base, pow / 2);	
}

double myPowDouble(double base, int pow) {

	double temp;
	bool negativePow = false;

	if(pow < 0) {
		negativePow = true;
		pow *= -1;
	}
	
	if(pow == 0)
		return 1;
	else if(pow % 2 == 0) 
		temp = myPowDouble(base, pow/2) * myPowDouble(base, pow/2);
	else 
		temp = base * myPowDouble(base, pow/2) * myPowDouble(base, pow/2);

	if(negativePow) 
		temp = 1 / temp;	
	
	return temp;
}

/* --------------------------------------------------------------------- */

/* -------------------------- Arrays (2D, 3D) -------------------------- */

/* Char */

char* allocateArrayChar(char *array, int size) {
	
	array = (char *) malloc(size * sizeof(char));

	return array;
}

char* reallocateArrayChar(char *array, int size) {
	
	array = realloc(array, size * sizeof(char));

	return array;
}

void printArrayChar(char *array, int arraySize) { 
    
    for(int i=0; i<arraySize; i++)
        printf("%c ", array[i]);

    printf("\n");
}

char** allocateMatrixChar(int rows, int coll) {
    
    char** matrix = (char **) malloc(rows * sizeof(char *));
    
    for(int i=0; i<rows; i++)
        matrix[i] = (char *) malloc(coll * sizeof(char)); 

    return matrix;
}

void reallocateMatrixChar(char **matrix, int rows, int coll) {
    
    matrix = realloc(matrix, rows * sizeof(char *)); 
    
    for(int i=0; i<rows; i++)
        matrix[i] = (char *) realloc(matrix[i], coll * sizeof(char));  
}

void freeAllocatedMatrixChar(char **matrix, int rows) { 
	
	for(int i=0; i<rows; i++) {
		free(matrix[i]);
	}
	
	free(matrix);
}

void printMatrixChar(char **matrix, int rows, int coll) { 

	if(rows < 1) {
		printf("[]");
		return;
	}
 
    for(int i=0; i<rows; i++) {
        for(int j=0; j<coll; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Int */

int* allocateArrayInt(int *array, int size) {
	
	array = (int *) malloc(size * sizeof(int));

	return array;
}

int* reallocateArrayInt(int *array, int size) {
	
	array = realloc(array, size * sizeof(int));

	return array;
}

void printArrayInt(int *array, int arraySize) { 
    
    for(int i=0; i<arraySize; i++)
        printf("%d ", array[i]);

    printf("\n");
}

int** allocateMatrixInt(int rows, int coll) {
    
    int** matrix = (int **) malloc(rows * sizeof(int *));
    
    for(int i=0; i<rows; i++)
        matrix[i] = (int *) malloc(coll * sizeof(int)); 
	
	return matrix;
}

void reallocateMatrixInt(int **matrix, int rows, int coll) {
    
    matrix = realloc(matrix, rows * sizeof(int *)); 
    
    for(int i=0; i<rows; i++)
        matrix[i] = (int *) realloc(matrix[i], coll * sizeof(int));   
}

void freeAllocatedMatrixInt(int **matrix, int rows) { 
	
	for(int i=0; i<rows; i++) {
		free(matrix[i]);
	}
	
	free(matrix);
}

void printMatrixInt(int **matrix, int rows, int coll) { 

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

/* --------------------------------------------------------------------- */

/* ---------------------------- Linked List ---------------------------- */

/* Definition for integer singly-linked list */

void listInitializeInt(struct ListNodeInt **list) {
   
    *list = (struct ListNodeInt*) malloc(sizeof(*list)); 

    (*list)->val = -1;
    (*list)->next = NULL;
}

void listPushInt(struct ListNodeInt *list, int val) {
    
    struct ListNodeInt *temp = (struct ListNodeInt*) malloc(sizeof(*temp));  
    
    /* Check if first element */ 
    if(list->val == -1 && list->next == NULL) {
        list->val = val;
        return;
    }
 
    /* Go to the end of linked list */ 
    while(list->next != NULL) {
        list = list->next;
    }

    temp->val = val;
    temp->next = NULL;
    list->next = temp;
}

void listInsertArrayInt(struct ListNodeInt *list, int *array, int arraySize) {
    
    int firstIndex = 0;
     
    /* Check if first element */
    if(list->val == -1 && list->next == NULL) {
        list->val = array[0];
        firstIndex = 1;
        if(arraySize == 1) return;
    }

    /* Go to the end of linked list */ 
    while(list->next != NULL) {
        list = list->next;
    }

    for(int i = firstIndex; i<arraySize; i++) {      
        struct ListNodeInt *temp = (struct ListNodeInt*) malloc(sizeof(*temp));
        temp->val = array[i];
        list->next = temp; 
        list = list->next;
    }    
    
    list->next = NULL;
}

int listPopInt(struct ListNodeInt *list) {
	
	int temp;
	int listSize = 0, i = 0;
	struct ListNodeInt *pnt = list;
	
	/* Count the number of list elements */	
	listSize = listCountInt(pnt);

	/* If the list is empty */
	if(listSize == 0)
		return '0';

	/* If the list has only one element */
	if(listSize == 1) {
		temp = pnt->val;
		pnt->val = ' ';
		return temp;
	}

	/* Go to second last node of the linked list */
	while(i < listSize - 2) {
		pnt = pnt->next;
		i++;
	}
	
	/* Get the value of the last node */	
	temp = pnt->next->val;
	
	/* Remove the last node */
	pnt->next = NULL;

	return temp;
}

void listPrintInt(struct ListNodeInt *list) {
    
    struct ListNodeInt *curr = list;
	
	/* Check if list is empty */
	if(list->val == -1 && list->next == NULL) {
		printf("Empty list\n");
		return;
	}
 
    while(curr->next != NULL) {
        printf("%d ", curr->val); 
        curr = curr->next;
    }

    printf("%d\n", curr->val);
}

int listCountInt(struct ListNodeInt *list) {
	
	struct ListNodeInt *curr = list;
	int count = 0;

	if(curr->val == -1 && curr->next == NULL)
		return 0;
	else count++;

	while(curr->next != NULL) {
		count++;
		curr = curr->next;
	}

	return count;
}

struct ListNodeInt* reverseListInt(struct ListNodeInt* head) {

	struct ListNodeInt *prev, *curr, *next, *dummy;

	// Check if Linked list is empty
	if(head->next == NULL && head->val == -1) 
		return head;

	curr = head;
	prev = NULL;

	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	}

	return prev;
}

void listFreeInt(struct ListNodeInt *list) {
    
    struct ListNodeInt *tmp;

    while(list->next != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

/* Definition for char singly-linked list */

void listInitializeChar(struct ListNodeChar **list) {
   
    *list = (struct ListNodeChar*) malloc(sizeof(*list)); 

    (*list)->val = ' ';
    (*list)->next = NULL;
}

void listPushChar(struct ListNodeChar *list, char val) {
    
    struct ListNodeChar *temp = (struct ListNodeChar*) malloc(sizeof(*temp));  
    
    /* Check if first element */ 
    if(list->val == ' ' && list->next == NULL) {
        list->val = val;
        return;
    }
 
    /* Go to the end of linked list */ 
    while(list->next != NULL) {
        list = list->next;
    }

    temp->val = val;
    temp->next = NULL;
    list->next = temp;
}

void listInsertArrayChar(struct ListNodeChar *list, char *array, int arraySize) {
    
    int firstIndex = 0;
     
    /* Check if first element */
    if(list->val == ' ' && list->next == NULL) {
        list->val = array[0];
        firstIndex = 1;
        if(arraySize == 1) return;
    }

    /* Go to the end of linked list */ 
    while(list->next != NULL) {
        list = list->next;
    }

    for(int i = firstIndex; i<arraySize; i++) {      
        struct ListNodeChar *temp = (struct ListNodeChar*) malloc(sizeof(*temp));
        temp->val = array[i];
        list->next = temp; 
        list = list->next;
    }    
    
    list->next = NULL;
}

char listPopChar(struct ListNodeChar *list) {
	
	char temp;
	int listSize = 0, i = 0;
	struct ListNodeChar *pnt = list;
	
	/* Count the number of list elements */	
	listSize = listCountChar(pnt);

	/* If the list is empty */
	if(listSize == 0)
		return '0';

	/* If the list has only one element */
	if(listSize == 1) {
		temp = pnt->val;
		pnt->val = ' ';
		return temp;
	}

	/* Go to second last node of the linked list */
	while(i < listSize - 2) {
		pnt = pnt->next;
		i++;
	}
	
	/* Get the value of the last node */	
	temp = pnt->next->val;
	
	/* Remove the last node */
	pnt->next = NULL;

	return temp;
}

void listPrintChar(struct ListNodeChar *list) {
    
    struct ListNodeChar *curr = list;
 
	/* Check if list is empty */
	if(list->val == ' ' && list->next == NULL) {
		printf("Empty list\n");
		return;
	}

    while(curr->next != NULL) {
        printf("%c ", curr->val); 
        curr = curr->next;
    }

    printf("%c\n", curr->val);
}

int listCountChar(struct ListNodeChar *list) {
	
	struct ListNodeChar *curr = list;
	int count = 0;

	if(curr->val == ' ' && curr->next == NULL) 
		return 0;
	else count++;

	while(curr->next != NULL) {
		count++;	
		curr = curr->next;
	}

	return count;
}

struct ListNodeChar* reverseListChar(struct ListNodeChar* head) {

	struct ListNodeChar *prev, *curr, *next, *dummy;

	// Check if Linked list is empty
	if(head->next == NULL && head->val == ' ') 
		return head;

	curr = head;
	prev = NULL;

	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	}

	return prev;
}

void listFreeChar(struct ListNodeChar *list) {
    
    struct ListNodeChar *tmp;

    while(list->next != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

/* --------------------------------------------------------------------- */
