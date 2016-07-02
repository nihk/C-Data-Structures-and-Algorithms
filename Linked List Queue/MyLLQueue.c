/* Linked list implementation of a Queue */

#include <stdio.h>
#include <stdlib.h>
#include "MyLLQueue.h"

// Function definitions
NodePtr makeNode(QueueData data) {
	NodePtr np = malloc(sizeof *np);
	np->data = data;
	np->next = NULL;
	return np;
}

QueueData makeQueueData(int n) {
	QueueData data;
	data.number = n;
	return data;
}

Queue initQueue(void) {
	Queue q = malloc(sizeof *q);
	q->head = q->tail = NULL;
	return q;
}

int isEmpty(Queue q) {
	return q->head == NULL;  // q->tail will also be NULL
}

void enqueue(Queue q, QueueData data) {
	NodePtr np = makeNode(data);
	if (isEmpty(q)) {
		q->head = q->tail = np;
	} else {
		// like an addLast() Linked List function
		q->tail->next = np;
		q->tail = np;
	}
}

// Shift head up 1 node, free original head
QueueData dequeue(Queue q) {
	if (isEmpty(q)) exit(1);
	QueueData hold = q->head->data;
	NodePtr temp = q->head;
	q->head = q->head->next;

	// for tidying up, since head will have gone past tail at this point
	if (q->head == NULL) q->tail = NULL;  

	free(temp);

	return hold;
}

// For simulating a stack using two Queues
void push(Queue stack, QueueData data) {
	enqueue(stack, data);
}

QueueData pop(Queue stack, Queue stackHelper) {
	QueueData data;
	data.number = -9999;  // In case of error
	while (!isEmpty(stack)) {
		data = dequeue(stack);
		if (isEmpty(stack)) {  // Last item was found
			break;
		}
		enqueue(stackHelper, data);
	}
	while (!isEmpty(stackHelper)) {
		enqueue(stack, dequeue(stackHelper));
	}

	return data;
}
