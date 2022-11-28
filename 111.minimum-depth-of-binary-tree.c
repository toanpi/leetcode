/*
 * @lc app=leetcode id=111 lang=c
 *
 * [111] Minimum Depth of Binary Tree
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

#define MIN(a, b)   ((a) < (b) ? (a) : (b))

void treeTraversal(struct TreeNode *root, int * depth, int *min)
{
  if (!root || *depth > *min)
  {
    return;
  }

  if (!root->left && !root->right)
  {
    // Reaching leaf
    if (*depth + 1 < *min)
    {
      *min = *depth + 1;
    }
    return;
  }

  (*depth)++;

  treeTraversal(root->left, depth, min);
  treeTraversal(root->right, depth, min);

  (*depth)--;
}

int minDepth(struct TreeNode* root)
{
  if (!root)
  {
    return 0;
  }

  int depth = 0;
  int min = INT_MAX;

  treeTraversal(root, &depth, &min);

  return min;
}

// @lc code=end

