#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * in ascending order using the Selection sort algorithm
 *
 * @array: pointer to the array list
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
size_t i, j, min, temp;

if (array == NULL || size < 2)
return;

/*iterate through the list one element at a time*/
for (i = 0; i < size - 1; i++)
{
min = i;/*keep track of idx i*/

/*iterate from idx 1 to compare with idx 0*/
for (j = i + 1; j < size; j++)
{
if (array[j] < array[min])
min = j;/*maintain the index*/
}
if (min == i)
continue;
/*then swap the elements in idx 0 with min idx*/
temp = array[i];
array[i] = array[min];
array[min] = temp;

print_array(array, size);
}
}
