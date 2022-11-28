/*
 * @lc app=leetcode id=606 lang=c
 *
 * [606] Construct String from Binary Tree
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

int countNodes(struct TreeNode *root)
{
  return root ? 1 + countNodes(root->left) + countNodes(root->right) : 0;
}

void convert(struct TreeNode *node, char *s, int *len)
{
  if (!node)
  {
    return;
  }

  (*len) += sprintf(&s[*len], "%d", node->val);

  if (!node->left && !node->right)
  {
    return;
  }

  s[(*len)++] = '(';
  convert(node->left, s, len);
  s[(*len)++] = ')';

  if (node->right)
  {
    s[(*len)++] = '(';
    convert(node->right, s, len);
    s[(*len)++] = ')';
  }
}

char *tree2str(struct TreeNode *root)
{
  int numNodes = countNodes(root);
  char *s = malloc((10 * numNodes + 1) * sizeof(char));
  int size = 0;

  convert(root, s, &size);

  s[size] = '\0';
  return s;
}

// @lc code=end

