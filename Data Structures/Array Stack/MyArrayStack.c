/* Array implementation of a Stack */

#include <stdio.h>
#include <stdlib.h>
#include "MyArrayStack.h"

// Function definitions
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
