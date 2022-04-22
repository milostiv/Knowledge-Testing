/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../../../mylib/mylib.h"

bool isValid(char * s){

}

int main(void) {

	struct ListNodeChar *list;
		
	char listArray[5] = {'a', 'b', 'c', 'd', 'e'};
	int listArraySize = sizeof(listArray)/sizeof(char);
	
	listInitializeChar(&list);
	listInsertArrayChar(list, listArray, listArraySize);	

	listPrintChar(list);	
	char temp = listPopChar(list);

	printf("%c\n", temp);
	
	listPrintChar(list);		
	listFreeChar(list);
	
	return EXIT_SUCCESS;
}
