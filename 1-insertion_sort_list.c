#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @node1: The first node (the one moving backward)
 * @node2: The second node (the one moving forward)
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
if (node1->prev)
node1->prev->next = node2;
else
*list = node2;

if (node2->next)
node2->next->prev = node1;

node2->prev = node1->prev;
node1->prev = node2;
node1->next = node2->next;
node2->next = node1;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort.
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *temp;

if (!list || !*list || !(*list)->next)
return;

curr = (*list)->next;
while (curr)
{
temp = curr;
curr = curr->next;

while (temp->prev && temp->n < temp->prev->n)
{
swap_nodes(list, temp->prev, temp);
print_list(*list);
}
}
}
