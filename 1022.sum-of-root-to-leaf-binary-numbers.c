/*
 * @lc app=leetcode id=1022 lang=c
 *
 * [1022] Sum of Root To Leaf Binary Numbers
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

void calSum(struct TreeNode *root, int *sum, int *num)
{
  if (!root)
  {
    return;
  }

  *num = ((*num) << 1) + root->val;

  if (!root->left && !root->right)
  {
    *sum += *num;
  }
  else
  {
    calSum(root->left, sum, num);
    calSum(root->right, sum, num);
  }

  (*num) >>= 1;
}

int sumRootToLeaf(struct TreeNode *root)
{
  int sum = 0;
  int num = 0;

  calSum(root, &sum, &num);

  return sum;
}

// @lc code=end

