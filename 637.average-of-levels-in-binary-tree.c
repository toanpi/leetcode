/*
 * @lc app=leetcode id=637 lang=c
 *
 * [637] Average of Levels in Binary Tree
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
#define max(a, b) ((a) > (b) ? (a) : (b))

int depthTree(struct TreeNode *root)
{
  return root ? 1 + max(depthTree(root->left), depthTree(root->right)) : 0;
}

void calSum(struct TreeNode *root, double *sum, int *cnt, int *level, int *max)
{
  if (!root)
  {
    return;
  }

  sum[*level] += root->val;
  cnt[*level]++;

  (*level)++;

  if (*level > *max)
  {
    *max = *level;
  }

  calSum(root->left, sum, cnt, level, max);
  calSum(root->right, sum, cnt, level, max);

  (*level)--;
}

double *averageOfLevels(struct TreeNode *root, int *returnSize)
{
  int depth = 1000;
  // int depth = depthTree(root);

  double *ret = calloc(depth, sizeof(double));
  int counts[depth];
  int level = 0;
  int max = 0;

  memset(counts, 0, sizeof(counts));

  calSum(root, ret, counts, &level, &max);

  depth = max;

  for (int i = 0; i < depth; i++)
  {
    ret[i] /= counts[i];
  }

  *returnSize = depth;

  return ret;
}

// @lc code=end

