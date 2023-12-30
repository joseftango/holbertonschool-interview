#include "sort.h"

/**
 * swap - Swap two numbers
 * @a: first value
 * @b: second value
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Find largest
 * @array: array
 * @n: start of the array
 * @i: current position
 * @size: size
 */
void heapify(int *array, int n, int i, size_t size)
{

	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[largest])
		largest = left;

	if (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, n, largest, size);
	}
}

/**
 * heap_sort - Build max heap
 * @array: array
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL)
		return;

	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
