/*
 * @lc app=leetcode id=226 lang=c
 *
 * [226] Invert Binary Tree
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

void invert(struct TreeNode *node)
{
  if(!node) return;

  struct TreeNode *temp = node->left;
  
  node->left = node->right;
  node->right = temp;

  invert(node->left);
  invert(node->right);
}

struct TreeNode *invertTree(struct TreeNode *root)
{
  invert(root);

  return root;
}

// @lc code=end

