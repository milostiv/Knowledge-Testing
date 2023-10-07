/* Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

struct ListNodeInt* reverseKGroup(struct ListNodeInt* head, int k) {

	int counter = 0;
	int linkedListSize;
	static bool firstIteration = true;	
	struct ListNodeInt *curr, *prev, *next;
	
	// Check if linked list is empty
	if(head->next == NULL && head->val == -1) 
		return head;

	curr = head;

	// Check if linked list has only one element
	while(curr->next != NULL) {
		counter++;
		curr = curr->next;
	}

	if(counter == 0) 
		return head;

	counter = 0;
	curr = head;
	if(firstIteration)
		prev = NULL;
	else 
		prev = curr;

	while(curr->next != NULL && counter < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	  	counter++;
	}

	linkedListSize = listCountInt(curr);

	if(linkedListSize > k) 
		head->next = reverseKGroup(next, k);
	else 
		head->next = curr;

	return prev;
}

int main(void) {

	/* Test 1: */
		
	struct ListNodeInt *list1, *list1Revesed;
	int list1Array[5] = {1, 2, 3, 4, 5};
	int list1ArraySize = sizeof(list1Array) / sizeof(int);
	int k = 2;

	listInitializeInt(&list1);
	listInsertArrayInt(list1, list1Array, list1ArraySize);		

	printf("List 1 before reversing: ");	
	listPrintInt(list1);	

	list1Revesed = reverseKGroup(list1, k);
	
	printf("List 1 after reversing: ");	
	listPrintInt(list1Revesed);	

	/* Test 2: */
		
	struct ListNodeInt *list2, *list2Revesed;
	int list2Array[5] = {1, 2, 3, 4, 5};
	int list2ArraySize = sizeof(list2Array) / sizeof(int);
	k = 3;

	listInitializeInt(&list2);
	listInsertArrayInt(list2, list2Array, list2ArraySize);		

	printf("List 2 before reversing: ");	
	listPrintInt(list2);	

	list2Revesed = reverseKGroup(list2, k);
	
	printf("List 2 after reversing: ");	
	listPrintInt(list2Revesed);	

	return EXIT_SUCCESS;
}
