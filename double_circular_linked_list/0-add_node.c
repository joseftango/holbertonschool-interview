#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/**
 * add_node_end - Add a new node to the end
 * @list: the head of list
 * @str: string
 * Return: ref of new node, or NULL on failure
**/
List *add_node_end(List **list, char *str)
{
	List *newNode, *temp;

	newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return (NULL);

	newNode->str = str;

	newNode->next = NULL;
	newNode->prev = NULL;

	if (*list == NULL)
	{
		*list = newNode;
		newNode->next = *list;
		newNode->prev = *list;
		return (*list);
	}
	else
	{
		temp = *list;
		while (temp->next != *list)
		{
		temp = temp->next;
		}

		temp->next = newNode;
		newNode->next = *list;
		newNode->prev = temp;
		(*list)->prev = newNode;
	}
	return (*list);
}


/**
 * add_node_begin - Add a new node to the start
 * @list: the head of list
 * @str: string
 * Return: ref of new node, or NULL on failure
**/
List *add_node_begin(List **list, char *str)
{
	List *newNode, *temp;

	newNode = malloc(sizeof(List));
	if (newNode == NULL)
		return (NULL);

	newNode->str = str;

	newNode->next = NULL;
	newNode->prev = NULL;

	if (*list == NULL)
	{
	*list = newNode;
	newNode->next = *list;
	newNode->prev = *list;
	return (*list);
	}
	else
	{
		temp = *list;
	while (temp->next != *list)
	{
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = *list;
	(*list)->prev = newNode;
	*list = newNode;
	}
	return (*list);
}
