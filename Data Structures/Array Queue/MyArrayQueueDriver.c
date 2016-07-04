/* Array-based implementation of a Queue */

#include <stdio.h>
#include <stdlib.h>
#include "MyArrayQueue.h"

int main(void) {
	const int len = 3;
	QueueData data[] = {
		makeQueueData(1),
		makeQueueData(2),
		makeQueueData(3)
	};

	// Basic demonstration of using a Queue
	Queue q = initQueue();

	for (int i = 0; i < len; i++) {
		enqueue(q, data[i]);
	}

	while (!empty(q)) {
		printQueueData(dequeue(q));
	}
	printf("\n");

	return 0;
}
