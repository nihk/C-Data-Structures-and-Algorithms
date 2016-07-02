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

StackData makeStackData(int n);
Stack initStack(void);
int empty(Stack s);
void push(Stack s, StackData data);
StackData pop(Stack s);
void printPop(Stack s);
int getStackIndex(int stackNum);
int CTCIEmpty(int stackNum);
void CTCIPush(int stackNum, int n);
int CTCIPop(int stackNum);
