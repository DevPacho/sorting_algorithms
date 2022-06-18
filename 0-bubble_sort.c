#include "sort.h"

/**
* bubble_sort - function that sorts an array of integers in ascending order.
* @array: array to sort.
* @size: array size.
*/

void bubble_sort(int *array, size_t size)
{
	unsigned int traverse, number, to_swap, check_order;

	if (!size || !array || size < 2)
		return;

	for (traverse = 0; traverse <= size; traverse++)
	{
		check_order = 0;

		for (number = 0; number < size - 1; number++)
		{
			if (array[number] > array[number + 1])
			{
				to_swap = array[number];
				array[number] = array[number + 1];
				array[number + 1] = to_swap;
				print_array(array, size);

				check_order = 1;
			}
		}
		if (check_order == 0)
			break;
	}
}
