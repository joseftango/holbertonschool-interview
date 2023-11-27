#include "lists.h"

/**
 * size - counting size of a list
 * @node: head
 * Return: size
**/

int size(listint_t *node)
{
	int counter = 0;

	while (node != NULL)
	{
		node = node->next;
		counter++;
	}
	return (counter);
}

/**
 * is_palindrome - checks if the list is palindrome
 * @head: the head of list
 * Return: 1 or 0
**/

int is_palindrome(listint_t **head)
{
	int counter = size(*head);
	int i = 0, j;
	listint_t *front, *rear;

	while (i != counter / 2)
	{
		front = rear = *head;
		for (j = 0; j < i; j++)
		{
			front = front->next;
		}
		for (j = 0; j < counter - (i + 1); j++)
		{
			rear = rear->next;
		}
		if (front->n != rear->n)
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
