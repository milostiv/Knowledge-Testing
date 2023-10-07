/* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list. */

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

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

int main(void) {
	
	struct ListNodeInt *sol;
	
	/* Test 1 */

	struct ListNodeInt *list1, *list2;

	listInitializeInt(&list1);
	listInitializeInt(&list2);	
	
	int list1Array[3] = {1,2,4};
	int list1Size = sizeof(list1Array)/sizeof(int);
	int list2Array[3] = {1,3,4};
	int list2Size = sizeof(list2Array)/sizeof(int);

	listInsertArrayInt(list1, list1Array, list1Size);	
	listInsertArrayInt(list2, list2Array, list2Size);

	sol = mergeTwoLists(list1, list2);	

	listPrintInt(sol);		
	listFreeInt(sol);
	
	/* Test 2 */

	struct ListNodeInt *list3, *list4;

	listInitializeInt(&list3);
	listInitializeInt(&list4);	

	sol = mergeTwoLists(list3, list4);	

	listPrintInt(sol);		
	listFreeInt(sol);

	/* Test 3 */

	struct ListNodeInt *list5, *list6;

	listInitializeInt(&list5);
	listInitializeInt(&list6);	

	listPushInt(list6, 0);

	sol = mergeTwoLists(list5, list6);	

	listPrintInt(sol);		
	listFreeInt(sol);

	return EXIT_SUCCESS;
}
