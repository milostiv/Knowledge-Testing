/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, 
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

#include <stdio.h>
#include <stdlib.h>

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

void listInsert(struct ListNode *list, int val) {
    
    struct ListNode *temp = (struct ListNode*) malloc(sizeof(*temp));  
     
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

}

/* Test */

int main(void) {
    
    struct ListNode *l1, *l2; 
    struct ListNode *curr;

    listInitialize(&l1);
    listInitialize(&l2);

    l1->val = 2;
    listInsert(l1, 4);
    listInsert(l1, 3);
    listPrint(l1);    

    l2->val = 5;
    listInsert(l2, 6);
    listInsert(l2, 4);
    listPrint(l2);
        
    return EXIT_SUCCESS;
}
