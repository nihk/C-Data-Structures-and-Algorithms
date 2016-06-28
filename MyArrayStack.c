/* Array implementation of a Stack */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int number;
} StackData;

typedef struct {
	int top;
	StackData arr[MAX];
} StackType, *Stack;

StackData makeStackData(int n) {
	StackData data;
	data.number = n;
	return data;
}

Stack initStack(void) {
	Stack s = malloc(sizeof *s);
	s->top = -1;
	return s;
}

int empty(Stack s) {
	return s->top == -1;
}

void push(Stack s, StackData data) {
	if (s->top == MAX - 1) exit(1);  // full
	s->top++;
	s->arr[s->top] = data;
}

StackData pop(Stack s) {
	if (empty(s)) exit(1);
	StackData data = s->arr[s->top];
	s->top--;
	return data;
}

void printPop(Stack s) {
	while (!empty(s)) {
		printf("%d ", pop(s).number);
	}
	printf("\n");
}

// CTCI question on implementing three stacks using a single array
int stackSize = MAX;
int stackContents[MAX * 3];
int stackPointers[] = { -1, -1, -1 };

int getStackIndex(int stackNum) {
	return MAX * stackNum + stackPointers[stackNum];
}

int CTCIEmpty(int stackNum) {
	return stackPointers[stackNum] == -1;
}

void CTCIPush(int stackNum, int n) {
	if (stackPointers[stackNum] >= stackSize - 1) exit(0);  // full
	stackPointers[stackNum]++;;
	stackContents[getStackIndex(stackNum)] = n;
}

int CTCIPop(int stackNum) {
	if (CTCIEmpty(stackNum)) exit(0);  // empty
	int value = stackContents[getStackIndex(stackNum)];
	stackPointers[stackNum]--;
	return value;
}

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
