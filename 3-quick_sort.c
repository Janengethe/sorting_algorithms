#include "sort.h"

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

sort(array, 0, size - 1, size);
}

/**
 * sort - function to call recursively and create new pivots
 * @array: array to be sorted
 * @start: beginning of sorting array
 * @end: end of sorting array
 * @size: size of array
 * Return: void
 */
void sort(int *array, size_t start, size_t end, size_t size)
{
size_t pivot;

if (end == 0 || end <= start)
return;

/*call partition to create pivot*/
pivot = partition(array, start, end, size);

/*after partitioning we find the position of sorted element(pivot)*/
if (pivot != 0 && pivot > start)
sort(array, start, pivot - 1, size);/*sort left hand size*/

if (pivot < size - 1)/*the other end*/
sort(array, pivot + 1, end, size);/*sort right hand size*/
}

/**
 * partition - function to partition array according to pivot
 * @array: array to be partitioned
 * @start: beginning of comparison index
 * @pivot: partition index
 * @size: size of array
 * Return: pivot
 */
size_t partition(int *array, size_t start, size_t pivot, size_t size)
{
size_t i;

for (i = start; i < pivot; i++)
{
if (array[i] < array[pivot])
{
if (i != start)/*i has incremented. < pivot*/
{
swap(&array[start], &array[i]);
print_array(array, size);
}
start++;
}
}
if (array[start] > array[pivot])
{
swap(&array[start], &array[pivot]);
pivot = start;
print_array(array, size);
}
return (pivot);
}

/**
 * swap - function to swap elements
 * @i: pointer to element 1
 * @j: pointer to element 2
 * Return: void
 */
void swap(int *i, int *j)
{
int temp = 0;

temp = *i;
*i = *j;
*j = temp;
}
