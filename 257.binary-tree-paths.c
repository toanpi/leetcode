/*
 * @lc app=leetcode id=257 lang=c
 *
 * [257] Binary Tree Paths
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
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void travel(struct TreeNode *root, char *path, int *pathLen, char **ret, int *retLen)
{
  if (!root)
  {
    return;
  }

  int n = sprintf(&path[*pathLen], (*pathLen) ? "->%d" : "%d", root->val);
  (*pathLen) += n;

  if (!root->left && !root->right)
  {
    ret[*retLen] = calloc((*pathLen) + 1, sizeof(char));
    strcpy(ret[(*retLen)++], path);

    (*pathLen) -= n;
    memset(&path[*pathLen], 0, n);
    return;
  }

  travel(root->left, path, pathLen, ret, retLen);
  travel(root->right, path, pathLen, ret, retLen);

  (*pathLen) -= n;
  memset(&path[*pathLen], 0, n);
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize)
{
  char **ret = calloc(100, sizeof(char *));
  int len = 0;
  char path[701] = {0};
  int pathLen = 0;

  travel(root, path, &pathLen, ret, &len);

  if(returnSize) *returnSize = len;
  return ret;
}

// @lc code=end

