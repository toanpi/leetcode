/*
 * @lc app=leetcode id=938 lang=c
 *
 * [938] Range Sum of BST
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

int rangeSumBST(struct TreeNode *root, int low, int high)
{
  if (!root)
  {
    return 0;
  }

  int sum = (root->val >= low && root->val <= high) ? root->val : 0;

  sum += rangeSumBST(root->left, low, high);
  sum += rangeSumBST(root->right, low, high);

  return sum;
}

// @lc code=end

