#include "sort.h"

/**
* tswap - function that swaps nodes of a doubly linked list.
* @list: doubly linked list.
* @current_node: current node guide.
* @previous_node: previous node guide.
*/

void tswap(listint_t **list, listint_t *current_node, listint_t *previous_node)
{
	if (previous_node->prev)
		previous_node->prev->next = current_node;
	else
		*list = current_node;

	if (current_node->next)
		current_node->next->prev = previous_node;

	current_node->next = previous_node;
	current_node->prev = previous_node->prev;
}

/**
* insertion_sort_list - function that sorts a doubly linked list of integers
* in ascending order.
* @list: doubly linked list to sort.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current_node = NULL;
	listint_t *next_to_current = NULL, *previous_to_current = NULL;

	if (!list || !*list)
		return;

	current_node = (*list);

	while (current_node)
	{
		previous_to_current = current_node->prev;
		next_to_current = current_node->next;

		while (previous_to_current && current_node->n < previous_to_current->n)
		{
			previous_to_current->next = current_node->next;
			tswap(list, current_node, previous_to_current);
			previous_to_current->prev = current_node;
			previous_to_current = current_node->prev;

			print_list(*list);
		}
		current_node = next_to_current;
	}
}