#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t i, index_main;
	int tmporal, swaping, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		tmporal = i;
		flag = 0;
		for (index_main = i + 1; index_main < size; index_main++)
		{
			if (array[tmporal] > array[index_main])
			{
				tmporal = index_main;
				flag += 1;
			}
		}
		swaping = array[i];
		array[i] = array[tmporal];
		array[tmporal] = swaping;
		if (flag != 0)
			print_array(array, size);
	}
}
