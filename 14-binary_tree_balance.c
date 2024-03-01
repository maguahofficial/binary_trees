#include "binary_trees.h"

/**
 * binary_tree_balance - This function measures the balance
 * factor of a binary tree.
 * @tree: (pointer) to the root node of the tree to measure
 * the balance factor.
 *
 * Return: If the tree is NULL, return 0, else return balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - this function measures the height of a binary tree.
 * @tree: (pointer) to the root node of the tree to measure the height.
 *
 * Return: If the tree is NULL, your function must return 0, else return height.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lvrble = 0, rvrble = 0;

		lvrble = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		rvrble = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lvrble > rvrble) ? lvrble : rvrble);
	}
	return (0);
}
