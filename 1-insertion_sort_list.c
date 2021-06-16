#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *prev;

if (list == NULL || (*list)->next == NULL)
return;

curr = *list;
/*Traverse forward*/
while (curr)
{

/*Traverse backward*/
prev = curr->prev;
while (prev && prev->n > curr->n)
{

/*swap*/
_swap(prev, curr, list);
print_list(*list);
prev = curr->prev;
}

curr = curr->next;
}
}

/**
 * _swap - helper function to swap the nodes
 * @node1: first node
 * @node2: second node
 * @head: head node
 * Return: void
 */
void _swap(listint_t *node1, listint_t *node2, listint_t **head)
{
listint_t *temp1, *temp2;

if (node1 == NULL || node2 == NULL)
return;

temp1 = node1->prev;/*backward pointer*/
temp2 = node2->next;/*forward pointer*/

if (temp1)
temp1->next = node2;

if (temp2)
temp2->prev = node1;

node1->next = temp2;
node1->prev = node2;
node2->next = node1;
node2->prev = temp1;

if (temp1 == NULL)
*head = node2;
}
