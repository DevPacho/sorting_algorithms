#include <stdio.h>
#include "sort.h"
void classify(int *array, int first_pos, int last_pos, size_t size);
int partition(int *array, int first_pos, int last_pos, size_t size);
void swap_ints(int *a, int *b);

/**
* quick_sort - Checks if there are contents in the input matrix
* If true, calls the sort function
* If false, does nothing
*
* @array: the array containing the integers
* @size: Is the size of the array
*/

void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
classify(array, 0, (int)(size - 1), size);
}

/**
* classify - recursively sorts the contents of an array,
* by using the quick sort algorithm
* @array: Array containing integers
* @first_pos: Index of the first element of the array
* @last_pos: Index of the last element of the array
* @size: Size of the array
*/

void classify(int *array, int first_pos, int last_pos, size_t size)
{
int pivot_ini;

if (first_pos >= last_pos)
return;
pivot_ini = partition(array, first_pos, last_pos, size);
classify(array, first_pos, pivot_ini - 1, size);
classify(array, pivot_ini + 1, last_pos, size);
}

/**
* partition - Function that applies the Lomuto partition method.
* The elements of the matrix that are between the first and last index
* from the location of the pivot
* elements smaller than the pivot will be in the left group
* the elements greater than the pivot will be in the right hand group
* the last element is always taken as the pivot.
*
* @array: The array
* @first_pos: index of the first element of the array
* @last_pos: Index of the last element of the array
* @size: Size of the array
* Return: Returns the new index taken by the pivot.
*/


int partition(int *array, int first_pos, int last_pos, size_t size)
{
int i, pivot_ini = first_pos;
int pivot = array[last_pos];

for (i = first_pos; i <= last_pos; i++)
{
if (array[i] < pivot)
{
if (array[i] != array[pivot_ini])
{
swap_ints(array + i, array + pivot_ini);
print_array((const int *)array, size);
}
pivot_ini++;
}
}
if (array[pivot_ini] != array[last_pos])
{
swap_ints(array + pivot_ini, array + last_pos);
print_array((const int *)array, size);
}
return (pivot_ini);
}

/**
* swap_ints - This function swaps received integers with each other.
* @a: Left side integer
* @b: Right side integer
*/

void swap_ints(int *a, int *b)
{
int c;

c = *a;
*a = *b;
*b = c;
}
