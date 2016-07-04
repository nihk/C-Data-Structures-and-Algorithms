#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
	char word[MAX];
} NodeData;

typedef struct node {
	NodeData data;
	struct node *next;
} Node, *NodePtr;

NodePtr makeNode(NodeData data);
NodeData makeNodeData(char word[]);
void reverse(NodePtr *head);
int length(NodePtr head);
void addLast(NodePtr head, NodeData data);
void addFirst(NodePtr *head, NodeData data);
NodePtr getReverse(NodePtr head);
void insert(NodePtr *head, int index, NodeData data);
void delete(NodePtr *head, int index);
void deleteNthNodeFromEnd(NodePtr *head, int n);
void deleteMiddle(NodePtr node);
NodePtr search(NodePtr head, NodeData data);
void printLL(NodePtr head);
void printReverseLL(NodePtr curr);
