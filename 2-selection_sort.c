#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using the Selection Sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: return void
 */

void selection_sort(int *array, size_t size)
{
	size_t min, i, j;

	if (!array || size < 2)
		return;
	i = 0;
	while (i < size)
	{
		min = i, j = i + 1;
		while (j < size)
		{
			if (*(array + j) < *(array + min))
				min = j;
			j++;
		}
		if (min != i)
		{
			*(array + i) = *(array + i) ^ *(array + min);
			*(array + min) = *(array + i) ^ *(array + min);
			*(array + i) = *(array + i) ^ *(array + min);
			print_array(array, size);
		}
		i++;
	}
}
