#include "binary_trees.h"

/**
 * binary_tree_node - function creates a binary tree node.
 * @parent:(a ponter) to the parent of the node to create.
 * @value:(int variable) The value to put in the new node.
 *
 * Return: if error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *newvrble;

	newvrble = malloc(sizeof(binary_tree_t));
	if (newvrble == NULL)
		return (NULL);

	newvrble->n = value;
	newvrble->parent = parent;
	newvrble->left = NULL;
	newvrble->right = NULL;

	return (newvrble);
}
