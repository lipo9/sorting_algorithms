#include "sort.h"

/**
 * _qsort - auxiliar function for the
 * quick_sort function
 * @a: input arrray
 * @l: index for the first element
 * @h: index for the last element
 * @size: size of the array
 * Return: no return
 */
void _qsort(int *a, int l, int h, int size)
{
	int i, p, w;


	if (l < h)
	{
		p = h;
		w = l;
		for (i = l; i < h; i++)
		{
			if (a[i] < a[p])
			{
				if (i != w)
				{
					a[i] = a[i] ^ a[w];
					a[w] = a[i] ^ a[w];
					a[i] = a[i] ^ a[w];
					print_array(a, size);
				}
				w++;
			}
		}
		if (w != p && a[w] != a[p])
		{
			a[w] = a[w] ^ a[p];
			a[p] = a[w] ^ a[p];
			a[w] = a[w] ^ a[p];
			print_array(a, size);
		}
		_qsort(a, l, w - 1, size);
		_qsort(a, w + 1, h, size);
	}
}


/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	_qsort(array, 0, size - 1, size);
}

