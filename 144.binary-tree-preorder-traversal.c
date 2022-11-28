/*
 * @lc app=leetcode id=144 lang=c
 *
 * [144] Binary Tree Preorder Traversal
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

void traversal(struct TreeNode *root, int *buf, int *bufLen)
{
  if(!root) return;

  buf[(*bufLen)++] = root->val;
 
  traversal(root->left, buf, bufLen);
  traversal(root->right, buf, bufLen);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize)
{
  int *ret = malloc(100 * sizeof(int));

  *returnSize = 0;

  traversal(root, ret, returnSize);

  return ret;
}

// @lc code=end

