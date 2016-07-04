#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "ResizeableArray.h"

int main(void) {
	// Demonstration of using a resizeable array
	// Initialize it and add arbitrary values to it
	int initialMaxSize = 2;
	ResizeableArray *arr = initResizeableArray(initialMaxSize);
	for (int i = 0; i < 10; i++) {
		add(arr, i * 3);
		printResizeableArray(arr);
	}

	// Insert at index
	insert(arr, 10, 12345);
	printResizeableArray(arr);

	// Get/set
	int index = 3;
	printf("\narr[%d] == %d\n\n", index, get(arr, index));
	set(arr, index, 500);
	printResizeableArray(arr);

	// Insert at index
	for (int i = 1; i <= 10; i++) {
		insert(arr, 2, i * 600);
		printResizeableArray(arr);
	}

	// Delete at index
	for (int i = 0; i < 5; i++) {
		delete(arr, arr->length - 1);
		delete(arr, 0);
		printResizeableArray(arr);
	}

	// Different (but functionally identical) ways to access array indices
	printf("\n\n%d %d %d\n", arr->arr[10], 10[arr->arr], *(arr->arr + 10));

	return 0;
}
