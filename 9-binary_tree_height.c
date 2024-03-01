#include "binary_trees.h"

/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: (pointer) to the root node of the tree to measure the height.
 *
 * Return: returns If tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lvrble = 0, rvrble = 0;

		lvrble = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		rvrble = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lvrble > rvrble) ? lvrble : rvrble);
	}
	return (0);
}
