#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 *
 * @list: head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *flist = (*list)->next, *temp = NULL, *position = NULL;
	unsigned int flag;

	while (flist)
	{
		position = flist;
		flist = flist->next;
		flag = 0;
		while (!flag)
		{
			if (position->prev != NULL)
			{
				if (position->n < position->prev->n)
				{
					temp = position->prev->prev;
					position->prev->next = position->next;
					position->prev->prev = position;
					if (position->next != NULL)
						position->next->prev = position->prev;
					position->next = position->prev;
					position->prev = temp;
					if (position->prev != NULL)
						position->prev->next = position;
					else
						*list = position;
					print_list(*list);
				} else
					flag = 1;
			} else
				flag = 1;
		}
	}
}
