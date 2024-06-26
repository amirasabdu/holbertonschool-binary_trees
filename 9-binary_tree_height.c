#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Description: This function calculates the height of a binary tree,
 * which is the maximum path length from the root to a leaf node.
 * Return: the height of the tree, or 0 if the tree is NULL.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight, rightHeight;

	if (tree == NULL)
		return (0);
	leftHeight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	rightHeight = tree->right ? 1 +  binary_tree_height(tree->right) : 0;

	return (leftHeight > rightHeight ? leftHeight : rightHeight);
}
