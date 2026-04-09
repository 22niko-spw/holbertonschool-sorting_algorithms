#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array.
 * @a: First integer.
 * @b: Second integer.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quick_sort.
 * @array: The array to partition.
 * @size: Total size of the array (for printing).
 * @low: Starting index of the partition.
 * @high: Ending index of the partition (pivot).
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] != array[high])
	{
		swap_ints(&array[i], &array[high]);
		print_array(array, size);
	}

	return (i);
}

/**
 * quick_recursion - Recursive helper for quick_sort.
 * @array: The array to sort.
 * @size: Total size of the array.
 * @low: Starting index.
 * @high: Ending index.
 */
void quick_recursion(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = lomuto_partition(array, size, low, high);
		quick_recursion(array, size, low, part - 1);
		quick_recursion(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers using Quick sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_recursion(array, size, 0, (int)size - 1);
}
