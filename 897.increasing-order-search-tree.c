/*
 * @lc app=leetcode id=897 lang=c
 *
 * [897] Increasing Order Search Tree
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

struct TreeNode *restruct(struct TreeNode *node, struct TreeNode *parent, struct TreeNode **root)
{
  if (!node) return parent;

  struct TreeNode *pre = restruct(node->left, parent, root);

  if (pre)
  {
    pre->right = node;
  }
  else
  {
    *root = node;
  }
  
  node->left = NULL;

  return restruct(node->right, node, root);
}

struct TreeNode *increasingBST(struct TreeNode *root)
{
  struct TreeNode *newRoot = NULL;
  restruct(root, NULL, &newRoot);

  return newRoot;
}

// @lc code=end

