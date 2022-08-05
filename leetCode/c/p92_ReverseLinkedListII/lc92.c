/* Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list. */

#include <stdio.h>
#include <stdlib.h>
#include "../../../mylib/mylib.h"

struct ListNodeInt* reverseBetween(struct ListNodeInt* head, int left, int right) {
	
	struct ListNodeInt *prev, *curr, *next, *start, *end;
	int counter = 1;

	// Check if linked list is empty
	if(head->next == NULL && head->val == -1)
		return head;

	curr = head;

	// Check if linked list has only one element
	while(curr->next != NULL) {
		counter++;
		curr = curr->next;
	}

	if(counter == 1) 
		return head;

	counter = 1;
	curr =head;

	// Go to left element
	while(counter < left) {
		prev = curr;
		curr = curr->next;
		counter++;
	}	

	start = prev;
	prev = curr;
	end = curr;
	curr = curr->next;
	next = NULL;

	while (counter < right) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;	
	  	counter++;
	}

	if(start) 
		start->next = prev;

	end->next = curr;		

	return start == NULL ? prev : head;		
}

int main(void) {

	/* Test 1: */

	struct ListNodeInt *list1, *list1Reversed;
	int list1Array[5] = {1, 2, 3, 4, 5};
	int list1ArraySize = sizeof(list1Array) / sizeof(int);
	int left = 2, right = 4;

	listInitializeInt(&list1);
	listInsertArrayInt(list1, list1Array, list1ArraySize);

	printf("List 1 before reversing: ");	
	listPrintInt(list1);

	list1Reversed = reverseBetween(list1, left, right);

	printf("List 1 after reversing: ");	
	listPrintInt(list1Reversed);

	/* Test 2: */

	struct ListNodeInt *list2, *list2Reversed;
	int list2Array = 5;
	int list2ArraySize = sizeof(list2Array) / sizeof(int);
	left = 1;
	right = 1;
	
	listInitializeInt(&list2);
	listPushInt(list2, list2Array);
	
	printf("List 2 before reversing: ");	
	listPrintInt(list2);

	list2Reversed = reverseBetween(list2, left, right);

	printf("List 2 after reversing: ");	
	listPrintInt(list2Reversed);
		
	return EXIT_SUCCESS;
}
