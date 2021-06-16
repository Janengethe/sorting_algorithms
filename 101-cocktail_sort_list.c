#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *nextnode, *curr;
int swapped;

if (list == NULL || !(*list) || (*list)->next == NULL)
return;

curr = (*list);
do {
swapped = 0;

while (curr->next)
{
nextnode = curr->next;

if (nextnode && curr->n > nextnode->n)
{
swapnodes(curr, nextnode, list);
swapped = 1;
print_list((*list));
}
else
curr = curr->next;
}

curr = curr->prev;
while (curr->prev)
{
nextnode = curr->prev;
if (nextnode && curr->n < nextnode->n)
{
swapnodes(nextnode, curr, list);
swapped = 1;
print_list((*list));
}
else
curr = curr->prev;
}
curr = curr->next;
} while (swapped);
}

/**
 * swapnodes - swaps both
 * @p: first node to swap
 * @c: second node to swap
 * @list: list to set null or not
 */
void swapnodes(listint_t *p, listint_t *c, listint_t **list)
{
if (!(p->prev))
{
p->next = c->next;
if (c->next)
c->next->prev = p;
c->next = p;
c->prev = NULL;
p->prev = c;
*list = c;
}

else
{
c->prev->next = c->next;
if (c->next)
c->next->prev = c->prev;
p->prev->next = c;
c->prev = p->prev;
p->prev = c;
c->next = p;
}
}
