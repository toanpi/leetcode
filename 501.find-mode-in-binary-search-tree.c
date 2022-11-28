/*
 * @lc app=leetcode id=501 lang=c
 *
 * [501] Find Mode in Binary Search Tree
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

int countNodes(struct TreeNode *root)
{
  return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
}

void maxOccur(struct TreeNode *node, int *max, int *cnt, int *val,
              int *ret, int *size)
{
  if (!node)
  {
    return;
  }

  maxOccur(node->left, max, cnt, val, ret, size);

  *cnt = (node->val != *val) ? 1 : *cnt + 1;
  *val = node->val;

  if (*cnt > *max)
  {
    *max = *cnt;
    *size = 1;
    ret[0] = *val;
  }
  else if (*cnt == *max)
  {
    ret[(*size)++] = *val;
  }

  maxOccur(node->right, max, cnt, val, ret, size);
}

int *findMode(struct TreeNode *root, int *returnSize)
{
  int numsNode = countNodes(root);
  int *ret = malloc(numsNode * sizeof(int));
  int max = 0;
  int cnt = 0;
  int val = INT_MIN;

  *returnSize = 0;

  maxOccur(root, &max, &cnt, &val, ret, returnSize);

  return ret;
}

// @lc code=end

