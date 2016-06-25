/* Linked list implementation of Stack */

#include <stdio.h>
#include <stdlib.h>

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
	StackData data1 = makeStackData(1);
	StackData data2 = makeStackData(2);
	StackData data3 = makeStackData(3);
	StackData data4 = makeStackData(4);

	// Basic demo of using a Stack
	Stack stack = initStack();
	push(stack, data1);
	push(stack, data2);
	push(stack, data3);
	while(!empty(stack)) {
		printf("%d ", pop(stack).number);
	}

	// Simulating a Queue using two Stacks. 
	// Input and output are both 1234
	Stack s1 = initStack();
	Stack s2 = initStack();
	
	enqueue(s1, data1);
	enqueue(s1, data2);
	enqueue(s1, data3);

	printf("\n\n%d", dequeue(s1, s2).number);
	printf("%d", dequeue(s1, s2).number);
	enqueue(s1, data4);
	printf("%d", dequeue(s1, s2).number);
	printf("%d\n\n", dequeue(s1, s2).number);

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
