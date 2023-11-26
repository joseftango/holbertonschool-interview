#include "binary_trees.h"

/**
* binary_tree_node - funtion that create a binary tree node
* @parent: pointer to the parent node of the node to create
* @value: value of the node
* Return: return void
**/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
		if (node == NULL)
			return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

		return (node);
}
