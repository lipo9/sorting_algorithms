#include "sort.h"


/**
 * _ssort - helper for the shell_sort function
 * @a: input arrray
 * @size: size of the array
 * @n: intervale
 * Return: no return
 */
void _ssort(int *a, int size, int n)
{
	int i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (*(a + j) < *(a + j - n))
			{
				*(a + j) = *(a + j) ^ *(a + j - n);
				*(a + j - n) = *(a + j) ^ *(a + j - n);
				*(a + j) = *(a + j) ^ *(a + j - n);
			}
		}
	}
	print_array(a, size);
}


/**
 * shell_sort - function that sorts an array
 * of integers in ascending order using the
 * Shell sort algorithm
 * @array: input arrray
 * @size: size of the array
 * Return: returns void
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;
	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}
