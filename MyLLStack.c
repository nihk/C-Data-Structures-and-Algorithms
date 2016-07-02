/* Linked list implementation of Stack */

#include <stdio.h>
#include <stdlib.h>
#include "MyLLStack.h"

// Function definitions
NodePtr makeNode(StackData n) {
	NodePtr np = malloc(sizeof *np);
	np->data = n;
	np->next = NULL;
	return np;
}

StackData makeStackData(int number) {
	StackData data;
	data.number = number;
	return data;
}

Stack initStack(void) {
	Stack s = malloc(sizeof *s);
	s->top = NULL;
	return s;
}

int empty(Stack s) {
	return s->top == NULL;
}

void push(Stack s, StackData n) {
	NodePtr np = makeNode(n);
	np->next = s->top;  // Same idea as addFirst()
	s->top = np;
}

// Shift head up one node and free original head
StackData pop(Stack s) {
	if (empty(s)) {
		exit(1);
	}
	StackData hold = s->top->data;
	NodePtr temp = s->top;
	s->top = s->top->next;
	free(temp);

	return hold;
}

// For using two stacks to simulate a Queue
void enqueue(Stack s1, StackData data) {
	push(s1, data);
}

StackData dequeue(Stack s1, Stack s2) {
	if (empty(s2)) {
		while(!empty(s1)) {
			StackData data = pop(s1);
			push(s2, data);
		}
	}

	return pop(s2);
}

// Common interview question to see if an expression consisting of brackets
// are balanced or not.
// For example: true for exp = “[()]{}{[()()]()}” and false for exp = “[(])”
int isBalanced(char expression[]) {
	char getPairMatch(char c);

	Stack stack = initStack();
	char c;
	int counter = 0;

	while ((c = expression[counter++]) != '\0') {
		if (c == '(' || c == '{' || c == '[') {
			push(stack, makeStackData(c));
		} else if (!empty(stack)) {
			StackData top = pop(stack);
			if (c != getPairMatch(top.number)) {
				return 0;
			}
		} else {
			return 0;
		}
	}

	// simply returning 1 would be incorrect, as an expression
	// like "(((((())" will make it this far. 
	return empty(stack);
}

char getPairMatch(char c) {
	switch(c) {
		case '(': return ')';
		case '[': return ']';
		case '{': return '}';
		default: return '\0';
	}
}

void TowerOfHanoi(int height, Stack origin, Stack destination, Stack buffer) {
	if (height <= 0) return;
	TowerOfHanoi(height - 1, origin, buffer, destination);
	push(destination, pop(origin));
	TowerOfHanoi(height - 1, buffer, destination, origin);
}
