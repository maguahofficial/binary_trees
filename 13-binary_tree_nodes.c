#include "binary_trees.h"

/**
 * binary_tree_nodes - this function counts the nodes with
 * at least 1 child in a binary tree.
 * @tree: (pointer) to the root node of the tree to count the number of nodes.
 *
 * Return: ff the tree is NULL, the function must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodesvrble = 0;

	if (tree)
	{
		nodesvrble += (tree->left || tree->right) ? 1 : 0;
		nodesvrble += binary_tree_nodes(tree->left);
		nodesvrble += binary_tree_nodes(tree->right);
	}
	return (nodesvrble);
}
