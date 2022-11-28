/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode *root, struct TreeNode *subRoot)
{
  if ((root == NULL) || (subRoot == NULL))
  {
    return (root == NULL) && (subRoot == NULL);
  }

  return (root->val == subRoot->val) &&
         isSameTree(root->left, subRoot->left) &&
         isSameTree(root->right, subRoot->right);
}

bool isSubtree(struct TreeNode *root, struct TreeNode *subRoot)
{
  if (!root)
  {
    return subRoot == NULL;
  }

  if (!subRoot)
  {
    return false;
  }

  if (!isSameTree(root, subRoot))
  {
    return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
  }

  return true;
}

// @lc code=end

