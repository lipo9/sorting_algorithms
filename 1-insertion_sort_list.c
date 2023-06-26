#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * an ascending order using the insertion sort algorithm
 * @list: a doubly linked list
 * Return: return void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	iter = *list;

	while (iter)
	{
		while (iter->next && (iter->n > iter->next->n))
		{
			tmp = iter->next;
			iter->next = tmp->next;
			tmp->prev = iter->prev;

			if (iter->prev)
				iter->prev->next = tmp;

			if (tmp->next)
				tmp->next->prev = iter;

			iter->prev = tmp;
			tmp->next = iter;

			if (tmp->prev)
				iter = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		iter = iter->next;
	}
}
