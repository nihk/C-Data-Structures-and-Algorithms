/* Linked list implementation of a Queue */

#include <stdio.h>
#include <stdlib.h>
#include "MyLLQueue.h"

int main(void) {
	const int len = 3;
	QueueData data[] = {
		makeQueueData(1),
		makeQueueData(2),
		makeQueueData(3)
	};

	// Basic Queue operations
	Queue q = initQueue();

	for (int i = 0; i < len; i++) {
		enqueue(q, data[i]);
	}

	while (!isEmpty(q)) {
		printf("%d ", dequeue(q).number);
	}

	printf("\n\n");

	// Simulate a stack using two queues
	Queue stack = initQueue();
	Queue stackHelper = initQueue();

	for (int i = 0; i < len; i++) {
		push(stack, data[i]);
	}

	for (int i = 0; i < len; i++) {
		printf("%d ", pop(stack, stackHelper).number);
	}

	printf("\n");
	return 0;
}
