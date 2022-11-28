/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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

void insert(struct TreeNode *root, int * buf, int *bufSize)
{
  if(!root)
  {
    return;
  }

  insert(root->left, buf, bufSize);

  buf[(*bufSize)++] = root->val;

  insert(root->right, buf, bufSize);
}

int *inorderTraversal(struct TreeNode *root, int *returnSize)
{
  int *ret = malloc(100 * sizeof(int));
  int size = 0;

  insert(root, ret, &size);

  *returnSize = size;
  return ret;
}

// @lc code=end

