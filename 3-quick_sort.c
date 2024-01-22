#include "sort.h"

/**
 * swap - swap items
 * @a: first
 * @b: second
*/

void swap(int *a, int *b)
{
	int temporaire = *a;

	*a = *b;
	*b = temporaire;
}

/**
 * lomuto - schema bjd hbi
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 * return the partition
*/

int lomuto(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * recursive - Function recursive
 * @array: array
 * @low: low
 * @high: high
 * @size: size
*/

void recursive(int *array, int low, int high, size_t size)
{
	int index;

	if (low < high)
	{
		index = lomuto(array, low, high, size);
		print_array(array, size);
		recursive(array, low, index - 1, size);
		recursive(array, index + 1, high, size);
	}
}

/**
 * quick_sort - quick sort
 * @array: array
 * @size: size
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive(array, 0, size - 1, size);
}
