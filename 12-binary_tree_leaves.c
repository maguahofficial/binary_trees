#include "binary_trees.h"

/**
 * binary_tree_leaves - this function counts the leaves in a binary tree.
 * @tree: (pointer) to the root node of the tree to count the leaves of.
 *
 * Return: returns the number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leavesvrble = 0;

	if (tree)
	{
		leavesvrble += (!tree->left && !tree->right) ? 1 : 0;
		leavesvrble += binary_tree_leaves(tree->left);
		leavesvrble += binary_tree_leaves(tree->right);
	}
	return (leavesvrble);
}
