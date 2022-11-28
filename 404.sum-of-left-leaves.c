/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
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

int sumOfLeftLeaves(struct TreeNode *root)
{
  if (!root)
  {
    return 0;
  }

  int sum = 0;
  struct TreeNode *l = root->left;

  if (l && !l->left && !l->right)
  {
    sum = l->val;
  }

  return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}

// @lc code=end

