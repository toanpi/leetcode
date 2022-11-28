/*
 * @lc app=leetcode id=653 lang=c
 *
 * [653] Two Sum IV - Input is a BST
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

int nodeCnt(struct TreeNode *root)
{
  return root ? 1 + nodeCnt(root->left) + nodeCnt(root->right) : 0;
}

void nodeGet(struct TreeNode *root, int *arr, int *len)
{
  if (root)
  {
    nodeGet(root->left, arr, len);
    arr[(*len)++] = root->val;
    nodeGet(root->right, arr, len);
  }
}


bool find(int *list, int l, int h, int n)
{
  while (l < h)
  {
    int val = list[l] + list[h];

    if (val == n)
    {
      return true;
    }
    else if (val > n)
    {
      h--;
    }
    else
    {
      l++;
    }
  }

  return false;
}

bool findTarget(struct TreeNode *root, int k)
{
  int numNode = 10000;
  // int numNode = nodeCnt(root);
  int nodes[numNode];

  numNode = 0;

  nodeGet(root, nodes, &numNode);

  return find(nodes, 0, numNode - 1, k);
}

// @lc code=end

