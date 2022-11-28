/*
 * @lc app=leetcode id=872 lang=c
 *
 * [872] Leaf-Similar Trees
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

void getLeaf(struct TreeNode *root, int *buf, int *len)
{
  if (!root)
  {
    return;
  }

  if (!root->left && !root->right)
  {
    buf[(*len)++] = root->val;
    return;
  }

  getLeaf(root->left, buf, len);
  getLeaf(root->right, buf, len);
}

bool leafSimilar(struct TreeNode *root1, struct TreeNode *root2)
{
  int leaves1[200] = {0};
  int leaves2[200] = {0};
  int len1 = 0;
  int len2 = 0;

  getLeaf(root1, leaves1, &len1);
  getLeaf(root2, leaves2, &len2);

  return (len1 == len2) && (memcmp(leaves1, leaves2, len1 * sizeof(int)) == 0);
}

// @lc code=end

