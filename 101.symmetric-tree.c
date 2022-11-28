/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
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

bool checkSymmetric(struct TreeNode *l, struct TreeNode *r)
{
  if (!l && !r)
  {
    return true;
  }

  if (!l || !r)
  {
    return false;
  }

  if (!checkSymmetric(l->left, r->right) || !checkSymmetric(l->right, r->left))
  {
    return false;
  }

  if (l->val != r->val)
  {
    return false;
  }

  return true;
}

bool isSymmetric(struct TreeNode *root)
{
  if (!root)
  {
    return false;
  }

  return checkSymmetric(root->left, root->right);
}

// @lc code=end

