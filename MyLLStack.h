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

// Function Prototypes
NodePtr makeNode(StackData n);
StackData makeStackData(int number);
Stack initStack(void);
int empty(Stack s);
void push(Stack s, StackData n);
StackData pop(Stack s);
// For using two stacks to simulate a Queue
void enqueue(Stack s1, StackData data);
StackData dequeue(Stack s1, Stack s2);
int isBalanced(char expression[]);
char getPairMatch(char c);
void TowerOfHanoi(int height, Stack startPeg, Stack endPeg, Stack workPeg);
