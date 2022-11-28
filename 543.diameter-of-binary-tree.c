/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
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

int lenght(struct TreeNode *root, int *max)
{
  if (!root)
  {
    return -1;
  }

  int lLen = lenght(root->left, max) + 1;
  int rLen = lenght(root->right, max) + 1;

  if (lLen + rLen > *max)
  {
    *max = lLen + rLen;
  }

  return lLen > rLen ? lLen : rLen;
}

int diameterOfBinaryTree(struct TreeNode *root)
{
  int diameter = 0;

  lenght(root, &diameter);

  return diameter;
}

// @lc code=end

