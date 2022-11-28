/*
 * @lc app=leetcode id=993 lang=c
 *
 * [993] Cousins in Binary Tree
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

void search(struct TreeNode *root, int *depth,
            int x, int y,
            int *xDepth, int *yDepth,
            struct TreeNode **xParent, struct TreeNode **yParent)
{
  if (!root)
  {
    return;
  }

  bool lFound = false;
  bool rFound = false;

  (*depth)++;

  if (!(*xParent) && root->left && root->left->val == x)
  {
    *xDepth = (*depth) + 1;
    *xParent = root;
    lFound = true;
  }

  if (!(*xParent) && root->right && root->right->val == x)
  {
    *xDepth = (*depth) + 1;
    *xParent = root;
    rFound = true;
  }

  if (!(*yParent) && root->left && root->left->val == y)
  {
    *yDepth = (*depth) + 1;
    *yParent = root;
    lFound = true;
  }

  if (!(*yParent) && root->right && root->right->val == y)
  {
    *yDepth = (*depth) + 1;
    *yParent = root;
    rFound = true;
  }

  if (!lFound)
  {
    search(root->left, depth, x, y, xDepth, yDepth, xParent, yParent);
  }

  if (!rFound)
  {
    search(root->right, depth, x, y, xDepth, yDepth, xParent, yParent);
  }

  (*depth)--;
}

bool isCousins(struct TreeNode *root, int x, int y)
{
  struct TreeNode *xParent = NULL;
  struct TreeNode *yParent = NULL;
  int xDepth = 0;
  int yDepth = 0;
  int curDepth = -1;

  search(root, &curDepth, x, y, &xDepth, &yDepth, &xParent, &yParent);

  return (xDepth == yDepth) && (xParent != yParent);
}

// @lc code=end

