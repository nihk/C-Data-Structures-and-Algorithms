/* Array-based implementation of a Queue */

#include <stdio.h>
#include <stdlib.h>
#include "MyArrayQueue.h"

// Function definitions
QueueData makeQueueData(int n) {
	QueueData data;
	data.number = n;
	return data;
}

Queue initQueue(void) {
	Queue q = malloc(sizeof *q);
	q->head = q->tail = 0;
	return q;
}

int empty(Queue q) {
	return q->head == q->tail;
}

void enqueue(Queue q, QueueData n) {
	if (q->tail == MAX - 1) q->tail = 0;  // array queues are cyclical
	else q->tail++;

	if (q->tail == q->head) exit(1);  // queue is full
	q->data[q->tail] = n;
}

QueueData dequeue(Queue q) {
	if (empty(q)) exit(1);

	if (q->head == MAX - 1) q->head = 0;  // array queues are cyclical
	else q->head++;

	return q->data[q->head];
}

void printQueueData(QueueData data) {
	printf("%d ", data.number);
}
