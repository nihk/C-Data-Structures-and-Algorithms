#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Searching.h"

// Assumes parameter arr is sorted
int binarySearch(int arr[], int len, int value) {
	int low = 0;
	int high = len - 1;

	while (low <= high) {
		int middle = (low + high) / 2;
		int item = arr[middle];
		if (value < item) {
			high = middle - 1;
		} else if (value > item) {
			low = middle + 1;
		} else {
			return middle;
		}
	}

	return -1;
}
