/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
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

bool hasPathSum(struct TreeNode *root, int targetSum)
{
  if (!root)
  {
    return false;
  }

  targetSum -= root->val;

  if (!root->left && !root->right)
  {
    return targetSum == 0;
  }

  return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

// @lc code=end

