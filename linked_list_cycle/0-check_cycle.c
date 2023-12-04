#include "lists.h"

/**
 * check_cycle - function that checks wether list is circular
 * @list: given list
 * Return: 1 or 0
**/

int check_cycle(listint_t *list)
{
	listint_t *tmp = list->next;

	if (list == NULL)
	return (1);

	while (tmp != NULL && tmp != list)
	{
		tmp = tmp->next;
	}

	return (tmp == list);
}
