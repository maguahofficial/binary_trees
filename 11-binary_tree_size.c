#include "binary_trees.h"

/**
 * binary_tree_size - This function measures the size of a binary tree.
 * @tree: (pointer0 to the root node of the tree to measure the size of.
 *
 * Return: returns The size of the tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sizevrble = 0;

	if (tree)
	{
		sizevrble += 1;
		sizevrble += binary_tree_size(tree->left);
		sizevrble += binary_tree_size(tree->right);
	}
	return (sizevrble);
}
