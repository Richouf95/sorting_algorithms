#include "sort.h"

/**
 * insertion_sort_list - sort doubly link list
 * @list: the list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *insertion;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		insertion = current;
		while (insertion->next != NULL &&
				insertion->n < insertion->prev->n)
		{
			if (insertion->next != NULL)
				insertion->next->prev = insertion->next;
			insertion->prev->next = insertion->next;
			insertion->next = insertion->prev;
			insertion->prev = insertion->prev->prev;

			if (insertion->prev != NULL)
				insertion->prev->next = insertion;
			if (insertion->next != NULL)
				insertion->next->prev = insertion;

			if (insertion->prev == NULL)
				*list = insertion;

			print_list(*list);
		}
		current = current->next;
	}
}
