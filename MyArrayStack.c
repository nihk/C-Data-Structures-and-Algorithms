/* Array implementation of a Stack */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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

	return 0;
}
