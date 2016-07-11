#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Sorting.h"

// Function definitions
void insertionSort(int arr[], int len) {
	for (int i = 1; i < len; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

void selectionSort(int arr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		int min = getSmallest(arr, i, len);
		if (min != i) {
			swap(arr, i, min);
		}
	}
}

int getSmallest(int arr[], int lo, int hi) {
	int min = lo;
	for (int j = lo + 1; j < hi; j++) {
		if (arr[j] < arr[min]) {
			min = j;
		}
	}

	return min;
}

void swap(int arr[], int i, int min) {
	int temp = arr[i];
	arr[i] = arr[min];
	arr[min] = temp;
}
