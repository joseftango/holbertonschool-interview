#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node, *parent;

    if (root == NULL)
        return NULL;

    new_node = malloc(sizeof(heap_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*root == NULL)
    {
        *root = new_node;
        new_node->parent = NULL;
        return new_node;
    }

    parent = find_parent(*root, value);

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    new_node->parent = parent;

    heapify_up(new_node);

    return new_node;
}

/**
 * find_parent - Finds the parent for the new node in the Max Heap
 * @root: Pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the parent node
 */
heap_t *find_parent(heap_t *root, int value)
{
    if (root->left == NULL || root->right == NULL)
        return root;

    if (is_complete(root->left) && !is_complete(root->right))
        return root;

    if (is_perfect(root->left) && is_complete(root->right))
        return root->left;

    if (is_perfect(root->left) && !is_complete(root->right))
        return find_parent(root->left, value);

    return find_parent(root->right, value);
}

/**
 * is_complete - Checks if a binary tree is complete
 * @root: Pointer to the root node of the tree
 * Return: 1 if complete, 0 otherwise
 */
int is_complete(heap_t *root)
{
    if (root == NULL)
        return 1;

    if (root->left == NULL && root->right == NULL)
        return 1;

    if ((root->left != NULL && root->right == NULL) ||
        (root->left == NULL && root->right != NULL))
        return 0;

    return is_complete(root->left) && is_complete(root->right);
}

/**
 * is_perfect - Checks if a binary tree is perfect
 * @root: Pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect(heap_t *root)
{
    int left_height, right_height;

    if (root == NULL)
        return 1;

    left_height = tree_height(root->left);
    right_height = tree_height(root->right);

    return left_height == right_height;
}

/**
 * tree_height - Computes the height of a binary tree
 * @root: Pointer to the root node of the tree
 * Return: Height of the tree
 */
int tree_height(heap_t *root)
{
    int left_height, right_height;

    if (root == NULL)
        return 0;

    left_height = tree_height(root->left);
    right_height = tree_height(root->right);

    return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * heapify_up - Restores the Max Heap property after insertion
 * @node: Pointer to the newly inserted node
 */
void heapify_up(heap_t *node)
{
    while (node->parent != NULL && node->n > node->parent->n)
    {
        swap_values(&(node->n), &(node->parent->n));
        node = node->parent;
    }
}

/**
 * swap_values - Swaps the values of two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_values(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

