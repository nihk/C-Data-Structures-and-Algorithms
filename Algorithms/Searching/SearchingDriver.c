#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Searching.h"

void printBinarySearchResult(int result, int value) {
	if (result == -1) {
		printf("%d was not found.\n", value);
	} else {
		printf("%d was found at index %d.\n", value, result);
	}
}

void searchAndPrintBinarySearchResult(int arr[], int len, int valueToFind) {
	int result = binarySearch(arr, len, valueToFind);
	printBinarySearchResult(result, valueToFind);
}

int main(void) {
	const int len = 10;
	int arr[] = { 2, 4, 7, 9, 13, 23, 45, 66, 89, 101 };

	searchAndPrintBinarySearchResult(arr, len, 89);
	searchAndPrintBinarySearchResult(arr, len, 12);
}
