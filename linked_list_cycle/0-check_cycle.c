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
	return (0);

	while (tmp != NULL)
	{
		if (tmp == list)
		return (1);
		tmp = tmp->next;
	}
	return (0);
}
