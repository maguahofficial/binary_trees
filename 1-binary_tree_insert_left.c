#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function inserts a node as a left-child of
 * of another in a binary tree.
 * @parent: (A pointer) to the node to insert the left-child in.
 * @value: (int variable) value to store in the new node.
 *
 * Return: If parent is NULL/ an error occurs - NULL.
 *         Otherwise - pointer to the new node.
 *
 * Description: If the parent already has left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *newvrble;

	if (parent == NULL)
		return (NULL);

	newvrble = binary_tree_node(parent, value);
	if (newvrble == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		newvrble->left = parent->left;
		parent->left->parent = newvrble;
	}
	parent->left = newvrble;

	return (newvrble);
}
