#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "ResizeableArray.h"

ResizeableArray *initResizeableArray(int size) {
	ResizeableArray *arr = malloc(sizeof *arr);
	arr->maxSize = size;
	arr->length = 0;
	arr->arr = malloc(size * sizeof *(arr->arr));
	return arr;
}

void resizeArray(ResizeableArray *arr) {
	printf("\tResizing from %d to %d\n", arr->maxSize, arr->maxSize * 2);	
	int *newArr = malloc(arr->maxSize * 2 * sizeof *newArr);  // alternatively, use realloc()
	for (int i = 0; i < arr->maxSize; i++) {
		newArr[i] = arr->arr[i];
	}
	arr->maxSize *= 2;
	int *hold = arr->arr;
	arr->arr = newArr;
	free(hold);
}

void add(ResizeableArray *arr, int n) {
	if (arr->length >= arr->maxSize) {
		resizeArray(arr);
	} 
	arr->length++;
	arr->arr[arr->length - 1] = n;
}

void insert(ResizeableArray *arr, int index, int n) {
	// Out of bounds (with respect to insertion)
	if (index > arr->length) {
		printf("Array index out of bounds\n");
		exit(0);
	}

	if (arr->length >= arr->maxSize) {
		resizeArray(arr);
	}

	// Appending to end of array
	if (index == arr->length) { 
		add(arr, n); 
		return;
	}

	// Make room for the new insertion
	arr->length++;  

	for (int i = arr->length - 1; i > index; i--) {
		arr->arr[i] = arr->arr[i - 1];
	}
	
	arr->arr[index] = n;
}

int isWithinBounds(ResizeableArray *arr, int index) {
	return index < arr->maxSize && index >= 0;
}

void delete(ResizeableArray *arr, int index) {
	if (!isWithinBounds(arr, index)) {
		printf("Array index out of bounds\n");
		exit(0);
	}
	for (int i = index; i < arr->length - 1; i++) {
		arr->arr[i] = arr->arr[i + 1];
	}

	arr->length--;
}

int get(ResizeableArray *arr, int index) {
	if (!isWithinBounds(arr, index)) {
		printf("Array index out of bounds\n");
		exit(0);
	}
	return arr->arr[index];
}

void set(ResizeableArray *arr, int index, int n) {
	if (!isWithinBounds(arr, index)) {
		printf("Array index out of bounds\n");
		exit(0);
	}
	arr->arr[index] = n;
}

int empty(ResizeableArray *arr) {
	return arr->length == 0;
}

void printResizeableArray(ResizeableArray *arr) {
	if (empty(arr)) return;
	printf("MaxSize: %d, Length: %d\n", arr->maxSize, arr->length);
	for (int i = 0; i < arr->length; i++) {
		printf("%d ", arr->arr[i]);
	}
	printf("\n");
}
