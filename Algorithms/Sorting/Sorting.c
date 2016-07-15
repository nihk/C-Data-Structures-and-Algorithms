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
	int k = low;

	while (i <= middle || j <= high) {
		if (i > middle) {
			temp[k++] = arr[j++];
		} else if (j > high) {
			temp[k++] = arr[i++];
		} else if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {  // arr[j] <= arr[i]
			temp[k++] = arr[j++];
		}
	}

	for (i = low; i <= high; i++) {
		arr[i] = temp[i];
	}
}

void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
