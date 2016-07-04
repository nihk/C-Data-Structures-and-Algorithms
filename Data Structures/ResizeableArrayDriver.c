#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "ResizeableArray.h"

int main(void) {
	int initialMaxSize = 2;
	ResizeableArray *arr = initResizeableArray(initialMaxSize);
	for (int i = 0; i < 10; i++) {
		add(arr, i * 3);
		printResizeableArray(arr);
	}
	insert(arr, 10, 12345);
	printResizeableArray(arr);

	int index = 3;
	printf("\narr[%d] == %d\n\n", index, get(arr, index));
	set(arr, index, 500);
	printResizeableArray(arr);

	for (int i = 1; i <= 10; i++) {
		insert(arr, 2, i * 600);
		printResizeableArray(arr);
	}

	for (int i = 0; i < 5; i++) {
		delete(arr, arr->length - 1);
		delete(arr, 0);
		printResizeableArray(arr);
	}

	return 0;
}
