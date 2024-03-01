#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - This function stores recursively each level in an
 * array of strings
 *
 * @tree: (Pointer variable) to the node to print
 * @offset: (interger variable)Offset to print
 * @depth: (interger variable)Depth of the node
 * @s: (variable) Buffer
 *
 * Return: returns returns length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
	char bvarble[6];
	int widthvarble, leftvble, right, is_left, ix;

	if (!tree)
		return (0);
	is_left = (tree->parent && tree->parent->left == tree);
	widthvarble = sprintf(bvarble, "(%03d)", tree->n);
	leftvble = print_t(tree->left, offset, depth + 1, s);
	right = print_t(tree->right, offset + leftvble + widthvarble, depth + 1, s);
	for (ix = 0; ix < widthvarble; ix++)
		s[depth][offset + leftvble + ix] = bvarble[ix];
	if (depth && is_left)
	{
		for (ix = 0; ix < widthvarble + right; ix++)
			s[depth - 1][offset + leftvble + widthvarble / 2 + ix] = '-';
		s[depth - 1][offset + leftvble + widthvarble / 2] = '.';
	}
	else if (depth && !is_left)
	{
		for (ix = 0; ix < leftvble + widthvarble; ix++)
			s[depth - 1][offset - widthvarble / 2 + ix] = '-';
		s[depth - 1][offset + leftvble + widthvarble / 2] = '.';
	}
	return (leftvble + widthvarble + right);
}

/**
 * _height - this function measures the height of a binary tree
 *
 * @tree: (Pointer) to the node to measures the height
 *
 * Return: returns the height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_lvrble;
	size_t height_rvrble;

	height_lvrble = tree->left ? 1 + _height(tree->left) : 0;
	height_rvrble = tree->right ? 1 + _height(tree->right) : 0;
	return (height_lvrble > height_rvrble ? height_lvrble : height_rvrble);
}

/**
 * binary_tree_print - this function prints a binary tree
 *
 * @tree: (Pointer) to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **ssx;
	size_t heightvrble, ivrble, jvrble;

	if (!tree)
		return;
	heightvrble = _height(tree);
	ssx = malloc(sizeof(*ssx) * (heightvrble + 1));
	if (!ssx)
		return;
	for (ivrble = 0; ivrble < heightvrble + 1; ivrble++)
	{
		ssx[ivrble] = malloc(sizeof(**ssx) * 255);
		if (!ssx[ivrble])
			return;
		memset(ssx[ivrble], 32, 255);
	}
	print_t(tree, 0, 0, ssx);
	for (ivrble = 0; ivrble < heightvrble + 1; ivrble++)
	{
		for (jvrble = 254; jvrble > 1; --jvrble)
		{
			if (ssx[ivrble][jvrble] != ' ')
				break;
			ssx[ivrble][jvrble] = '\0';
		}
		printf("%s\n", ssx[ivrble]);
		free(ssx[ivrble]);
	}
	free(ssx);
}
