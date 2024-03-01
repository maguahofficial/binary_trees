#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t depth(const binary_tree_t *tree);
const binary_tree_t *get_leaf(const binary_tree_t *tree);
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - this function checks if a node is a leaf of a binary tree.
 * @node:(its a pointer) to the node to check.
 *
 * Return: If the node is a leaf,returns 1, otherwise,returns 0.
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * depth - the function returns the depth of a given
 * node in a binary tree.
 * @tree: (its a pointer) to the node to measure the depth of.
 *
 * Return: returns the depth of node.
 */
size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
 * get_leaf - function returns a leaf of a binary tree.
 * @tree: (pointer variable) to the root node of the tree to find a leaf in.
 *
 * Return: returns pointer to the first encountered leaf.
 */
const binary_tree_t *get_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? get_leaf(tree->left) : get_leaf(tree->right));
}

/**
 * is_perfect_recursive - this function checks if a binary
 * tree is perfect recursively.
 * @tree: (pointer) to the root node of the tree to check.
 * @leaf_depth: (size_t variable)The depth of one leaf in the binary tree.
 * @level: (size_t variable)Level of current node.
 *
 * Return: If the tree is perfect,returns 1, otherwise returns 0.
 */
int is_perfect_recursive(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaf(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_perfect_recursive(tree->left, leaf_depth, level + 1) &&
		is_perfect_recursive(tree->right, leaf_depth, level + 1));
}

/**
 * binary_tree_is_perfect - this function checks if a binary tree is perfect.
 * @tree: (pointer variable) to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect,returns 0.
 *         Otherwise, returns 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_perfect_recursive(tree, depth(get_leaf(tree)), 0));
}
