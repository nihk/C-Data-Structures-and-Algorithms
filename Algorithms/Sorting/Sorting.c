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

int getSmallest(int arr[], int lo, int hi) {
	int min = lo;
	for (int j = lo + 1; j < hi; j++) {
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

void quicksort1(int arr[], int low, int high) {
	if (low < high) {
		int divisionPoint = partition1(arr, low, high);
		quicksort1(arr, low, divisionPoint - 1);
		quicksort1(arr, divisionPoint + 1, high);
	}
}

// pivot ends up in its final sorted position
int partition1(int arr[], int low, int high) {
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

void quicksort2(int arr[], int low, int high) {
	if (low < high) {
		int divisionPoint = partition2(arr, low, high);
		quicksort2(arr, low, divisionPoint);
		quicksort2(arr, divisionPoint + 1, high);
	}
}

// pivot does not end up in its final sorted position
int partition2(int arr[], int low, int high) {
	// random pivot to try and avoid worst case O(n^2)
	swap(arr, low, random(low, high));
	int pivot = arr[low];
	low--;
	high++;

	while (low < high) {
		do {
			high--;
		} while (arr[high] > pivot);

		do {
			low++;
		} while (arr[low] < pivot);

		if (low < high) {
			swap(arr, low, high);
		}
	}

	return high;
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

// returns a random i where m <= i <= n
int random(int m, int n) {
	int offset = rand()/(RAND_MAX + 1.0) * (n - m + 1);
	return m + offset;
}
