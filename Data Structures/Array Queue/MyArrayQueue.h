/* Array-based implementation of a Queue */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int number;
} QueueData;

typedef struct {
	int head;
	int tail;
	QueueData data[MAX];
} QueueType, *Queue;

// Function prototypes
QueueData makeQueueData(int n);
Queue initQueue(void);
int empty(Queue q);
void enqueue(Queue q, QueueData n);
QueueData dequeue(Queue q);
void printQueueData(QueueData data);
