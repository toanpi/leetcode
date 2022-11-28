/*
 * @lc app=leetcode id=617 lang=c
 *
 * [617] Merge Two Binary Trees
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

struct TreeNode *mergeTrees(struct TreeNode *root1, struct TreeNode *root2)
{
  if (root1 && root2)
  {
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);

    return root1;
  }
  else
  {
    return root1 ? root1 : root2;
  }
}

// @lc code=end

