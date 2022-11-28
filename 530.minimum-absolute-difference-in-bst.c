/*
 * @lc app=leetcode id=530 lang=c
 *
 * [530] Minimum Absolute Difference in BST
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

void trarvel(struct TreeNode *node, int *minDis, int *preVal)
{
  if ((!node) || ((*minDis) == 0))
  {
    return NULL;
  }

  trarvel(node->left, minDis, preVal);

  if (*preVal >= 0)
  {
    *minDis = min(*minDis, abs(node->val - *preVal));
  }

  *preVal = node->val;

  trarvel(node->right, minDis, preVal);
}

int getMinimumDifference(struct TreeNode *root)
{
  int ret = INT_MAX;
  int val = INT_MIN;

  trarvel(root, &ret, &val);

  return ret;
}

// @lc code=end

