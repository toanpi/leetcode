/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
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

  traversal(root->left, buf, bufLen);
  traversal(root->right, buf, bufLen);

  buf[(*bufLen)++] = root->val;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize)
{
  int *ret = malloc(100 * sizeof(int));

  *returnSize = 0;

  traversal(root, ret, returnSize);

  return ret;
}


// @lc code=end

