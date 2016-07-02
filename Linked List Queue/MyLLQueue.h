/* Linked list implementation of a Queue */

#include <stdio.h>
#include <stdlib.h>

// Struct definitions
typedef struct {
	int number;
} QueueData;

typedef struct node {
	QueueData data;
	struct node *next;
} Node, *NodePtr;

typedef struct {
	NodePtr head;
	NodePtr tail;
} QueueType, *Queue;

// Function prototypes
NodePtr makeNode(QueueData data);
QueueData makeQueueData(int n);
Queue initQueue(void);
int isEmpty(Queue q);
void enqueue(Queue q, QueueData data);
QueueData dequeue(Queue q);
// For simulating a stack using two Queues
void push(Queue stack, QueueData data);
QueueData pop(Queue stack, Queue stackHelper);
