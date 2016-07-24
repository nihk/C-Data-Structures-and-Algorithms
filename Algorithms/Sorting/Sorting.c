#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
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

int getSmallest(int arr[], int low, int high) {
	int min = low;
	for (int j = low + 1; j < high; j++) {
		if (arr[j] < arr[min]) {
			min = j;
		}
	}

	return min;
}

void mergeSort(int arr[], int low, int high) {
	if (low < high) {
		int middle = (low + high) / 2;
		mergeSort(arr, low, middle);
		mergeSort(arr, middle + 1, high);
		merge(arr, low, middle, high);
	}
}

void merge(int arr[], int low, int middle, int high) {
	int temp[MAX];
	int i = low;
	int j = middle + 1;
	int index = low;

	while (i <= middle || j <= high) {
		if (i > middle) {
			temp[index] = arr[j++];
		} else if (j > high) {
			temp[index] = arr[i++];
		} else if (arr[i] < arr[j]) {
			temp[index] = arr[i++];
		} else {  // arr[j] <= arr[i]
			temp[index] = arr[j++];
		}
		index++;
	}

	for (i = low; i <= high; i++) {
		arr[i] = temp[i];
	}
}

void quicksort(int arr[], int low, int high) {
	if (low < high) {
		int divisionPoint = partition(arr, low, high);
		quicksort(arr, low, divisionPoint - 1);
		quicksort(arr, divisionPoint + 1, high);
	}
}

int partition(int arr[], int low, int high) {
	// random pivot to try and avoid worst case O(n^2)
	swap(arr, low, random(low, high));
	int pivot = arr[low];
	int lastSmall = low;
	for (int i = low + 1; i <= high; i++) {
		if (arr[i] < pivot) {
			lastSmall++;
			swap(arr, i, lastSmall);
		}
	}
	swap(arr, low, lastSmall);
	return lastSmall;
}

void heapsort(int arr[], int high) {
	for (int i = high / 2; i >= 0; i--) {
		int key = arr[i];
		siftDown(arr, key, i, high);
	}
	for (int i = high; i > 0; i--) {
		int key = arr[i];
		arr[i] = arr[0];
		siftDown(arr, key, 0, i - 1);
	}
}

void siftDown(int arr[], int key, int root, int last) {
	int bigger = 2 * root + 1;

	while (bigger <= last) {
		if (bigger < last && arr[bigger + 1] > arr[bigger]) { 
			bigger++;
		}

		if (key >= arr[bigger]) {
			break;
		}

		arr[root] = arr[bigger];
		root = bigger;
		bigger = 2 * root + 1;
	}

	arr[root] = key;
}

void shellsort(int arr[], int len, int interval) {
	for (int i = interval; i < len; i++) {
		int key = arr[i];
		int j = i - interval;
		while (j >= 0 && arr[j] > key) {
			arr[j + interval] = arr[j];
			j -= interval;
		}
		arr[j + interval] = key;
	}
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// returns a random i where m <= i <= n
int random(int m, int n) {
	int offset = rand() / (RAND_MAX + 1.0) * (n - m + 1);
	return m + offset;
}
