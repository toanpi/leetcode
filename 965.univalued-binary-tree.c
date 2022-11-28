/*
 * @lc app=leetcode id=965 lang=c
 *
 * [965] Univalued Binary Tree
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


bool check(struct TreeNode *node, int val)
{
  if (!node)
  {
    return true;
  }

  return node->val == val &&
         check(node->left, val) &&
         check(node->right, val);
}

bool isUnivalTree(struct TreeNode *root)
{
  return check(root, root->val);
}

// @lc code=end

