#include "binary_trees.h"

/**
 * binary_tree_insert_right - This Function inserts a node as the right-child
 * of another in a binary tree.
 * @parent: (A pointer) to the node to insert the right-child in.
 * @value:(int variable) The value to store in the new node.
 *
 * Return: If parent is NULL/ an error occurs - NULL.
 *         Otherwise - a pointer to new node.
 *
 * Description: If the parent already has a right-child, the new node
 *              takes its place and the old right-child is set as
 *              the right-child of  new node.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *newvrble;

	if (parent == NULL)
		return (NULL);

	newvrble = binary_tree_node(parent, value);
	if (newvrble == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		newvrble->right = parent->right;
		parent->right->parent = newvrble;
	}
	parent->right = newvrble;

	return (newvrble);
}
