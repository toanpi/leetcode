/*
 * @lc app=leetcode id=783 lang=c
 *
 * [783] Minimum Distance Between BST Nodes
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

void calDiff(struct TreeNode *root, int *min, int *preVal)
{
  if (!root || *min == 0)
  {
    return;
  }

  calDiff(root->left, min, preVal);

  if (abs(*preVal - root->val) < *min)
  {
    *min = abs(*preVal - root->val);
  }

  *preVal = root->val;

  calDiff(root->right, min, preVal);
}

int minDiffInBST(struct TreeNode *root)
{
  int min = INT_MAX;
  int val = INT_MAX;

  calDiff(root, &min, &val);

  return min;
}

// @lc code=end

