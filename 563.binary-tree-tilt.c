/*
 * @lc app=leetcode id=563 lang=c
 *
 * [563] Binary Tree Tilt
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

int calDiff(struct TreeNode *root, int *sum)
{
  if (!root)
  {
    return 0;
  }

  int l = calDiff(root->left, sum);
  int r = calDiff(root->right, sum);

  *sum += abs(l - r);

  return l + r + root->val;
}

int findTilt(struct TreeNode *root)
{
  int sum = 0;

  calDiff(root, &sum);

  return sum;
}

// @lc code=end

