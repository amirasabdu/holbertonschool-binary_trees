#include "binary_trees.h"
/**
 * do_complete_recursive - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 * @depth: tree depth.
 * @level: recursion level.
 * @is_left_finish: flag the finish.
 * Return: If the tree is NULL or not complete fail, 0.
 *         Otherwise, 1.
 */
int do_complete_recursive(const binary_tree_t *tree, int depth,
		int level, int *is_left_finish)
{
	if (depth == level + 1)
	{
		if (*is_left_finish == 0)
		{
			if (tree->left != NULL && tree->right != NULL)
			{
				*is_left_finish = 0;
				return (1);
			}
			if (tree->left != NULL && tree->right == NULL)
			{
				*is_left_finish = 1;
				return (1);
			}
			if (tree->left == NULL && tree->right != NULL)
			{
				*is_left_finish = 1;
				return (0);
			}
		}
		else
		{
			if (tree->left == NULL && tree->right == NULL)
				return (1);
			else
				return (0);
		}
	}
	if (tree->left == NULL && tree->right == NULL)
		return (level == depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	int left_res = do_complete_recursive(tree->left, depth,
			level + 1, is_left_finish);
	int right_res = do_complete_recursive(tree->right, depth,
			level + 1, is_left_finish);
	return (left_res && right_res);
}
/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the tree to traverse.
 *
 * Return: If the tree is NULL or not complete, 0.
 *         Otherwise, 1.
 * Description: Upon malloc failure, exits with a status code of 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    int is_left_finish = 0;

    if (tree == NULL)
        return (0);
    return (do_complete_recursive(tree, binary_tree_height(tree),
			    0, &is_left_finish));
}
