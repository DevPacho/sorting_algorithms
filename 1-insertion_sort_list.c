#include "sort.h"

/**
* sorted_insert - function to insert a new node in sorted way.
* @list: list to sort.
* @new_node: node to insert in sorted way.
*/

void sorted_insert(listint_t **list, listint_t *new_node)
{
	listint_t *current_node;

	if (*list == NULL)
		*list = new_node;

	else if ((*list)->n >= new_node->n)
	{
		new_node->next = *list;
		new_node->next->prev = new_node;
		*list = new_node;
	}

	else
	{
		current_node = *list;

		while (current_node->next != NULL && current_node->next->n < new_node->n)
			current_node = current_node->next;

		new_node->next = current_node->next;

		if (current_node->next != NULL)
			new_node->next->prev = new_node;

		current_node->next = new_node;
		new_node->prev = current_node;
	}
}

/**
* insertion_sort_list - function that sorts a doubly linked list
* of integers in ascending order.
* @list: list to sort.
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL, *current_node = NULL, *next_iteration = NULL;

	if (!list || !*list)
		return;

	current_node = *list;

	while (current_node != NULL)
	{
		next_iteration = current_node->next;

		current_node->prev = current_node->next = NULL;
		sorted_insert(&sorted, current_node);
		current_node = next_iteration;

		print_list(*list);
	}
	*list = sorted;
}
