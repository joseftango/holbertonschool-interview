#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void heapify(int *array, int n, int i, size_t size);
void swap(int *a, int *b);

#endif
