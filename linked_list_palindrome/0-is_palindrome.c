#include "lists.h"

/**
 * is_palindrome - checks if the list is palindrome
 * @head: the head of list
 * Return: 1 or 0
**/

int is_palindrome(listint_t **head)
{
	int palindrome[1024];
	int i, j, num = 0;

	if ((*head) == NULL || head == NULL)
		return (1);

	if ((*head)->next == NULL)
		return (1);

	while (*head != NULL)
	{
		palindrome[num] = (*head)->n;
		num++;
		*head = (*head)->next;
	}

	for (i = 0, j = num - 1 ; i < (num / 2); i++, j--)
	{
		if (palindrome[i] != palindrome[j])
			return (0);
	}

	return (1);
}
