#include "sort.h"

/**
 * bubble_sort - Bubble method to sor array
 * @array: the array
 * @size: the array size
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int done, temp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		done = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				done = 1;
				print_array(array, size);
			}
		}
		if (done == 0)
			break;
	}
}
