/* Linked list implementation of Stack */

#include <stdio.h>
#include <stdlib.h>
#include "MyLLStack.h"

int main(void) {
	const int len = 4;
	StackData data[] = {
		makeStackData(1),
		makeStackData(2),
		makeStackData(3),
		makeStackData(4)
	};

	// Basic demo of using a Stack
	Stack stack = initStack();
	for (int i = 0; i < len; i++) {
		push(stack, data[i]);
	}

	while (!empty(stack)) {
		printf("%d ", pop(stack).number);
	}

	printf("\n\n");


	// Simulating a Queue using two Stacks.
	Stack s1 = initStack();
	Stack s2 = initStack();
	
	// Enqueue all items but the last of the data array
	for (int i = 0; i < len - 1; i++) {
		enqueue(s1, data[i]);
	}

	// Dequeue the first two items
	for (int i = 0; i < 2; i++) printf("%d ", dequeue(s1, s2).number);
	// Even after dequeueing has begun, enqueueing can continue and the
	// output will still behave like a Queue
	enqueue(s1, data[len - 1]);
	// Dequeue remaining items
	for (int i = 2; i < len; i++) printf("%d ", dequeue(s1, s2).number);

	printf("\n\n");


	// Testing for a balanced expression consisting of brackets/parens/braces
	char expression[] = "[()]{}{[()()]()}";
	if (isBalanced(expression)) {
		printf("%s is balanced\n", expression);
	} else {
		printf("%s is NOT balanced\n", expression);
	}

	char expression2[] = "(((((())";
	if (isBalanced(expression2)) {
		printf("%s is balanced\n", expression2);
	} else {
		printf("%s is NOT balanced\n", expression2);
	}
	printf("\n");


	// Demo of Tower of Hanoi algorithm
	int height = 5;
	Stack startPeg = initStack();
	Stack endPeg = initStack();
	Stack workPeg = initStack();

	// Push all items to the starting peg
	for (int i = height; i >= 1; i--) {
		push(startPeg, makeStackData(i));
	}

	TowerOfHanoi(height, startPeg, endPeg, workPeg);

	// All items have moved to the ending peg after algorithm completes
	while (!empty(endPeg)) {
		printf("%d\n", pop(endPeg).number);
	}

	return 0;
}
