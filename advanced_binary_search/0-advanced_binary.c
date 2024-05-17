#include "search_algos.h"


/**
 * print_array - Print an array
 * @array: Array to print
 * @left: Left index
 * @right: Right index
 *
 * Return: 1 if the array is printed, 0 otherwise
 */
int print_array(int *array, int left, int right)
{
	int i = 0;

	if (left > right)
		return (0);

	printf("Searching in array: ");

	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
	return (1);
}


/**
 * advanced_binary_rec - Search for a value in a sorted array of integers
 * @array: Array to search
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 *
 * Return: Index where the value is located, -1 otherwise
 */
int advanced_binary_rec(int *array, int left, int right, int value)
{
	int middle;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	middle = left + (right - left) / 2;
	if (array[middle] == value)
	{
		if (middle == left || array[middle] != value)
			return (middle);
		else
			return (advanced_binary_rec(array, left, middle, value));
	}
	else if (array[middle] > value)
	{
		return (advanced_binary_rec(array, left, middle, value));
	}
	else
	{
		return (advanced_binary_rec(array, middle + 1, right, value));
	}
}


/**
 * advanced_binary - Search for a value in a sorted array of integers
 * @array: Array to search
 * @size: Size of the array
 * @value: Value to search for
 *
 * Return: Index where the value is located, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_binary_rec(array, 0, size - 1, value));
}