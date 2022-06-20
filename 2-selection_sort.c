#include "sort.h"

/**
* selection_sort - function that sorts an array of integers in ascending order.
* @array: array to sort.
* @size: array size.
*/

void selection_sort(int *array, size_t size)
{
	unsigned int traverse, current_number, current_minimum_number, to_swap;

	if (!size || !array || size < 2)
		return;

	for (traverse = 0; traverse < size - 1; traverse++)
	{
		int check_order = 0;
		current_minimum_number = traverse;

		for (current_number = traverse + 1; current_number < size; current_number++)
		{
			if (array[current_number] < array[current_minimum_number])
				current_minimum_number = current_number;
		}

		if (traverse != current_minimum_number)
		{
			to_swap = array[traverse];
			array[traverse] = array[current_minimum_number];
			array[current_minimum_number] = to_swap;

			print_array(array, size);

			check_order = 1;
		}

		if (check_order == 0)
			break;
	}
}
