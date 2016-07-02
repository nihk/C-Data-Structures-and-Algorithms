/* Array implementation of a Stack */

#include <stdio.h>
#include <stdlib.h>
#include "MyArrayStack.h"

int main(void) {
	// Basic use of an array-based Stack
	const int len = 3;
	StackData data[] = {
		makeStackData(1),
		makeStackData(2),
		makeStackData(3)
	};
	Stack s = initStack();
	
	for (int i = 0; i < len; i++) {
		push(s, data[i]);
	}

	printPop(s);
	printf("\n");

	// CTCI question on implementing three stacks using a single array
	for (int i = 1; i <= 5; i++) {
		CTCIPush(0, i);
		CTCIPush(1, i * 2);
		CTCIPush(2, i * 3);
	}

	for (int i = 0; i < 3; i++) {
		while (!CTCIEmpty(i)) {
			printf("%d ", CTCIPop(i));
		}
		printf("\n");
	}

	return 0;
}
