#include "sort.h"
/**
 * check_tree - swiftdown check
 * @array: pointer to array
 * @size: size of the pointer
 * @size_init: original size of the array
 * @i: index as a root of the tree
 *
**/
void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int n, branch_1, branch_2;
	size_t br_1, br_2;

	br_1 = i * 2 + 1;
	br_2 = br_1 + 1;
	branch_1 = array[br_1];
	branch_2 = array[br_2];
	if (((br_1 < size) && (br_2 < size) &&
		(branch_1 >= branch_2 && branch_1 > array[i]))
		|| ((br_1 == size - 1) && branch_1 > array[i]))
	{
		n = array[i];
		array[i] = branch_1;
		array[br_1] = n;
		print_array(array, size_init);
	}
	else if ((br_1 < size) && (br_2 < size) &&
		(branch_2 > branch_1 && branch_2 > array[i]))
	{
		n = array[i];
		array[i] = branch_2;
		array[br_2] = n;
		print_array(array, size_init);
	}
	if (br_1 < size - 1)
		check_tree(array, size_init, size, br_1);
	if (br_2 < size - 1)
		check_tree(array, size_init, size, br_2);
}
/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap
 * sort algorithm
 * @array: pointer to array
 * @size: size of the pointer
 *
**/
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;
	for (i = 0; i < size / 2 ; i++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - i);
	}
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}

}
