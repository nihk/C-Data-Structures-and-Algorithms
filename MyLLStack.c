/* Linked list implementation of Stack */

#include <stdio.h>
#include <stdlib.h>

// Struct definitions
typedef struct {
	int number;
} StackData;

typedef struct node {
	StackData data;
	struct node *next;
} Node, *NodePtr;

typedef struct {
	NodePtr top;
} StackType, *Stack;

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
	
	// Enqueue first three pieces of data
	for (int i = 0; i < 3; i++) {
		enqueue(s1, data[i]);
	}

	for (int i = 0; i < 2; i++) printf("%d ", dequeue(s1, s2).number);
	// Even after dequeueing has begun, enqueueing can continue and the
	// output will still behave like a Queue
	enqueue(s1, data[len - 1]);
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

	return 0;
}
