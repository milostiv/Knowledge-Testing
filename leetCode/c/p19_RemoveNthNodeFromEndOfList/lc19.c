/**
 * Given the head of a linked list, remove the nth node from the end of the list and return its head.
*/

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

struct ListNodeInt* removeNthFromEnd(struct ListNodeInt* head, int n) {

	int ListSize = 1;
	struct ListNodeInt *pnt;

	pnt = head;

	/* Find the size of the list */
	while(pnt->next != NULL) {
		ListSize++;	
		pnt = pnt->next;	
	}	

	if(ListSize == 1 && n == 1) {
		printf("Empty list!\n");
		return head;
	}
	else if(ListSize == 1 && n > 1) {
		printf("'n' greater then number of list elements!\n");
		return head;
	}

	pnt = head;
	
	for(int i=1; i<n+1; i++) {
		pnt = pnt->next;
	}

	while(pnt->next != NULL) {
		pnt = pnt->next;
		head = head->next;
	}
	
	head->next = (head->next)->next;
}

int main(void) {
	
	struct ListNodeInt *list1, *list2, *list3;

	/* Test 1 */

	int list1Array[5] = {1,2,3,4,5};	
	int listArraySize = sizeof(list1Array)/sizeof(int);

	listInitializeInt(&list1);	
	listInsertArrayInt(list1, list1Array, listArraySize);

	removeNthFromEnd(list1, 2);

	listPrintInt(list1);
	listFreeInt(list1);

	/* Test 2 */

	int list2Array = 1;
	listArraySize = 1;

	listInitializeInt(&list2);
	listPushInt(list2, list2Array);
	
	removeNthFromEnd(list2, 1);

	listFreeInt(list2);

	/* Test 3 */

	int list3Array[2] = {1,2};	
	listArraySize = sizeof(list3Array)/sizeof(int);

	listInitializeInt(&list3);
	listInsertArrayInt(list3, list3Array, listArraySize);

	removeNthFromEnd(list3, 1);

	listPrintInt(list3);
	listFreeInt(list3);
	
	return EXIT_SUCCESS;
}
