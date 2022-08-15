#include "sort.h"

/**
*swap - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swap(int *array, int item1, int item2)
{

	int tmporal;

	tmporal = array[item1];
	array[item1] = array[item2];
	array[item2] = tmporal;
}
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t gap_btn = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (gap_btn < size / 3)
		gap_btn = 3 * gap_btn + 1;
	while (gap_btn >= 1)
	{
		for (i = gap_btn; i < size; i++)
			for (index = i; index >= gap_btn &&
			 (array[index] < array[index - gap_btn]); index -= gap_btn)
				swap(array, index, index - gap_btn);
		print_array(array, size);
		gap_btn /= 3;
	}
}
