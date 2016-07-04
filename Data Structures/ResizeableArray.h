#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct {
	int maxSize, length, *arr;
} ResizeableArray;

ResizeableArray *initResizeableArray(int size);
void resizeArray(ResizeableArray *arr);
void add(ResizeableArray *arr, int n);
void insert(ResizeableArray *arr, int index, int n);
int isWithinBounds(ResizeableArray *arr, int index);
void delete(ResizeableArray *arr, int index);
int get(ResizeableArray *arr, int index);
void set(ResizeableArray *arr, int index, int n);
int empty(ResizeableArray *arr);
void printResizeableArray(ResizeableArray *arr);
