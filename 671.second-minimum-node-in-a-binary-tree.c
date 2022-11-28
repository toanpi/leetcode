/*
 * @lc app=leetcode id=671 lang=c
 *
 * [671] Second Minimum Node In a Binary Tree
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

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int secondMin(struct TreeNode *root, int n)
{
  if (!root)
  {
    return -1;
  }

  if (root->val != n)
  {
    return root->val;
  }

  int minL = secondMin(root->left, n);
  int minR = secondMin(root->right, n);

  return (minL >= 0 && minR >= 0) ? min(minL, minR) : max(minL, minR);
}

int findSecondMinimumValue(struct TreeNode* root)
{
  return secondMin(root, root->val);
}
// @lc code=end

