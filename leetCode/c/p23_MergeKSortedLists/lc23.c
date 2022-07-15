/* You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

struct ListNodeInt* mergeTwoLists(struct ListNodeInt* list1, struct ListNodeInt* list2) {
	
	struct ListNodeInt *pnt;	
	listInitializeInt(&pnt);

	struct ListNodeInt *head = pnt;

	// Check if both lists are empty
	if(list1->next == NULL && list1->val == -1 && list2->next == NULL && list2->val == -1) 
		return head;

	while ((list1->next != NULL) || (list2->next != NULL)) {
	
		// If end of list2 is reached, but not the end of list1	
		if((list1->next != NULL) && (list2->next == NULL)) {
			
			while(list1->next != NULL) {
				listPushInt(pnt, list1->val);
				list1 = list1->next;
			}

			break;
		}

		// If end of list1 is reached, but not the end of list2
		if((list1->next == NULL) && (list2->next != NULL)) {
				
			while(list2->next != NULL) {
				listPushInt(pnt, list2->val);
				list2 = list2->next;
			}

			break;
		}
	
		if(list1->val <= list2->val) {
			listPushInt(pnt, list1->val);
			list1 = list1->next;
		}
		else {	
			listPushInt(pnt, list2->val);
			list2 = list2->next;
		}

	}
	
	// Add the last list elements
	if(list1->val <= list2->val) {
		listPushInt(pnt, list1->val);
		listPushInt(pnt, list2->val);
	}
	else{
		listPushInt(pnt, list2->val);
		listPushInt(pnt, list1->val);
	}

	return head;
}

void mergeKLists(struct ListNodeInt** lists, int listsSize) {

	struct ListNodeInt *sol;
	struct ListNodeInt *emptyList;

	listInitializeInt(&emptyList);	
		
	/* Check if list is empty */
	if(listsSize == 0) {
		listPrintInt(emptyList);
		return;
	}
	/* Check if all the rows in the list are empty */	
	else {
		bool allRowsEmpty = true;
		for(int i=0; i<listsSize; i++) {
			if(lists[i]->val != -1 && lists[i]->next != NULL)
				allRowsEmpty = false;	
		}
	
		if(allRowsEmpty) {
			listPrintInt(emptyList);
			return;
			}
	}	

	sol = lists[0];

	for(int i=1; i<listsSize; i++) {
		sol = mergeTwoLists(sol, lists[i]);		
	}

	listPrintInt(sol);
}

int main(void) {

	struct ListNodeInt *sol;

	/* Test */

	struct ListNodeInt **lists1;
	struct ListNodeInt *list1, *list2, *list3;

	listInitializeInt(&list1);	
	listInitializeInt(&list2);
	listInitializeInt(&list3);

	int list1Array[3] = {1, 4, 5};	
	int list1Size = sizeof(list1Array)/sizeof(int);
	int list2Array[3] = {1, 3, 4};
	int list2Size = sizeof(list2Array)/sizeof(int);
	int list3Array[2] = {2, 6};
	int list3Size = sizeof(list3Array)/sizeof(int);

	listInsertArrayInt(list1, list1Array, list1Size);
	listInsertArrayInt(list2, list2Array, list2Size);
	listInsertArrayInt(list3, list3Array, list3Size);

	lists1[0] = list1;	
	lists1[1] = list2;
	lists1[2] = list3;
	
	printf("Test 1:\n");
	mergeKLists(lists1, 3); 

	/* Test 2 */

	printf("\nTest 2:\n");
	/* Simulate empty list */
	mergeKLists(lists1, 0); 	
	
	return EXIT_SUCCESS;
}
