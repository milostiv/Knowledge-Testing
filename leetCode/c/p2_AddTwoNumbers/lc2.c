/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

void listInitialize(struct ListNode **list) {
   
    *list = (struct ListNode*) malloc(sizeof(*list)); 

    (*list)->val = -1;
    (*list)->next = NULL;
}

void listInsertArray(struct ListNode *list, int *array, int arraySize) {
    
    int firstIndex = 0;
     
    /* Check if first element */
    if(list->val < 0) {
        list->val = array[0];
        firstIndex = 1;
        if(arraySize == 1) return;
    }

    /* Go to the end of linked list */ 
    while(list->next != NULL) {
        list = list->next;
    }

    for(int i = firstIndex; i<arraySize; i++) {      
        struct ListNode *temp = (struct ListNode*) malloc(sizeof(*temp));
        temp->val = array[i];
        list->next = temp; 
        list = list->next;
    }    
    
    list->next = NULL;
}

void listInsertSingle(struct ListNode *list, int val) {
    
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(*temp));  
    
    /* Check if first element */ 
    if(list->val < 0) {
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

void listPrint(struct ListNode *list) {
    
    struct ListNode *curr = list;
 
    while(curr->next != NULL) {
        printf("%d ", curr->val); 
        curr = curr->next;
    }

    printf("%d\n", curr->val);
}

void listFree(struct ListNode *list) {
    
    struct ListNode *tmp;

    while(list->next != NULL) {
        tmp = list;
        list = list->next;
        free(tmp);
    }
}

int listFormNumber(struct ListNode *list) {
    
    int sum = 0, mul = 1;

    do { 
        sum += (list->val)*mul;
        mul *= 10;
        list = list->next;
    } while(list != NULL);

    return sum;
}

struct ListNode* addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
   
    struct ListNode *tmp;
    int sum = 0, mul = 1; 

    listInitialize(&tmp);

    sum += listFormNumber(l1);
    sum += listFormNumber(l2);
      
    while(true) {
        listInsertSingle(tmp, sum % 10);
        sum /= 10;
        if(sum == 0)
            break;
    }

    return tmp;
}

/* Test */

void testFunction(struct ListNode *l1, struct ListNode *l2, struct ListNode *sol, int testNumber) {
      
    bool identical = true; 
    float timeSpent = 0;
    struct ListNode *curr; 
    
    clock_t tic = clock();
    
    curr = addTwoNumbers(l1, l2);
    
    clock_t toc = clock();
 
    timeSpent = (double) (toc - tic) * 1000000 / CLOCKS_PER_SEC;
    
    if(curr->next == NULL && sol->next == NULL) {
        if(curr->val != sol->val)
            identical = false;
    } 

    do {
        if(sol->next == NULL && curr -> next != NULL) {
            identical = false;
            break;
        } 
        if(curr->val != sol->val) {
            identical = false;
            break;
        }
        curr = curr->next;
        sol = sol->next;  
    } while(curr != NULL);

    printf("\nTEST%d: ", testNumber);

    if(identical) 
        printf("PASSED IN %.2fus\n", timeSpent);
    else  
        printf("FAILED\n");
}

int main(void) {
    
    struct ListNode *l1, *l2, *sol; 

    /* Test 1 */

    listInitialize(&l1);
    listInitialize(&l2);
    listInitialize(&sol);
    
    int array1[3] = {2, 4, 3};
    listInsertArray(l1, array1, 3);
    
    int array2[3] = {5, 6, 4};
    listInsertArray(l2, array2, 3);

    int array3[3] = {7, 0, 8};
    listInsertArray(sol, array3, 3);

    testFunction(l1, l2, sol, 1);
         
    listFree(l1);
    listFree(l2);
    listFree(sol);
    
    /* Test 2 */
 
    listInitialize(&l1);
    listInitialize(&l2);
    listInitialize(&sol);
 
    listInsertSingle(l1, 0);

    listInsertSingle(l2, 0); 

    listInsertSingle(sol, 0);

    testFunction(l1, l2, sol, 2);
    
    listFree(l1);
    listFree(l2);
    listFree(sol);
    
    /* Test 3 */
         
    listInitialize(&l1);
    listInitialize(&l2);
    listInitialize(&sol);
    
    int array4[7] = {9, 9, 9, 9, 9, 9, 9}; 
    listInsertArray(l1, array4, 7);

    int array5[4] = {9, 9, 9, 9};
    listInsertArray(l2, array5, 4);
    
    int array6[8] = {8, 9, 9, 9, 0, 0, 0, 1};
    listInsertArray(sol, array6, 8);

    testFunction(l1, l2, sol, 3);

    return EXIT_SUCCESS;
}
