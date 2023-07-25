#include "sort.h"

/**
* counting_sort - counting sort algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
*/
void counting_sort(int *array, size_t size)
{
	int k, max;
	int *count = NULL, *copy = NULL;
	size_t j, temp, total = 0;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (j = 0, max = 0; j < size; j++)
	{
		copy[j] = array[j];
		if (array[j] > max)
			max = array[j];
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(copy);
		return;
	}
	for (k = 0; k <= max; k++)
		count[k] = 0;
	for (k = 0; k < size; k++)
		count[array[j]] += 1;
	for (k = 0; k <= max; k++)
	{
		temp = count[k];
		count[k] = total;
		total += temp;
	}
	for (j = 0; j < size; j++)
	{
		array[count[copy[j]]] = copy[j];
		count[copy[j]] += 1;
	}
	print_array(count, max + 1);
	free(count);
	free(copy);
}
