/* Given the head of a singly linked list, reverse the list, and return the reversed list. */

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main(void) {

	/* Test 1: */
		
	struct ListNodeInt *list1, *list1Reversed;
	int list1Array[5] = {1, 2, 3, 4, 5};
	int list1ArraySize = sizeof(list1Array) / sizeof(int);

	listInitializeInt(&list1);
	listInsertArrayInt(list1, list1Array, list1ArraySize);		

	printf("List 1 before reversing: ");	
	listPrintInt(list1);

	list1Reversed = reverseListInt(list1);	

	printf("List 1 after reversing: ");	
	listPrintInt(list1Reversed);

	/* Test 2: */
	
	struct ListNodeInt *list2, *list2Reversed;
	int list2Array[2] = {1, 2};
	int list2ArraySize = sizeof(list2Array) / sizeof(int);
	
	listInitializeInt(&list2);
	listInsertArrayInt(list2, list2Array, list2ArraySize);		

	printf("List 2 before reversing: ");	
	listPrintInt(list2);

	list2Reversed = reverseListInt(list2);	
	
	printf("List 2 after reversing: ");	
	listPrintInt(list2Reversed);

	/* Test 3: */

	struct ListNodeInt *list3, *list3Reversed;

	listInitializeInt(&list3);

	printf("List 3 before reversing: ");	
	listPrintInt(list3);

	list3Reversed = reverseListInt(list3);

	printf("List 3 after reversing: ");	
	listPrintInt(list3Reversed);
	
	return EXIT_SUCCESS;
}
