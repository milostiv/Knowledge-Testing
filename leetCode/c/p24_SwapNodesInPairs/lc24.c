/* Given a linked list, swap every two adjacent nodes and return its head. 

You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.) */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

struct ListNodeInt* swapPairs(struct ListNodeInt* head) {
	
	struct ListNodeInt *dummyNode, *current;
	struct ListNodeInt *tempFirst, *tempSecond;

	listInitializeInt(&dummyNode);

	dummyNode->next = head;
	current = dummyNode;

	while(current->next != NULL && current->next->next != NULL) {
		
		tempFirst = current->next;
		tempSecond = current->next->next;

		tempFirst->next = tempSecond->next;
		
		current->next = tempSecond;
		tempSecond->next = tempFirst;
		
		current = current->next->next;			
	}	

	return dummyNode->next;
}

int main(void) {
	
	/* Test 1 */

	struct ListNodeInt *list1, *sol1;
	int list1Array[4] = {1, 2, 3, 4};
	int list1Size = sizeof(list1Array) / sizeof(int);

	listInitializeInt(&list1);
	listInsertArrayInt(list1, list1Array, list1Size);	
	printf("Test 1:\n");
	listPrintInt(list1);
	printf("-> ");

	sol1 = swapPairs(list1);	
	listPrintInt(sol1);

	/* Test 2 */
	
	struct ListNodeInt *list2, *sol2;
	int list2Array[1] = {1};
	int list2Size = sizeof(list2Array) / sizeof(int);
	
	listInitializeInt(&list2);
	listInsertArrayInt(list2, list2Array, list2Size);	
	printf("Test 2:\n");
	listPrintInt(list2);
	printf("-> ");

	sol2 = swapPairs(list2);	
	listPrintInt(sol2);

	return EXIT_SUCCESS;
}
