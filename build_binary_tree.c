// CPP program to construct binary
// tree from given array in level
// order fashion Tree Node

/* A binary tree node has data,
pointer to left child and a
pointer to right child */
struct TreeNode
{
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

#define NULL_NODE   -10000000

/* Helper function that allocates a
new node */
struct TreeNode* newNode(int data)
{
  struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  node->val = data;
  node->left = node->right = NULL;
  return (node);
}

struct TreeNode * build(int data[], int len)
{
  if (len <= 0)
  {
    return NULL;
  }

  struct TreeNode *res = NULL;
  struct TreeNode *a[len];

  for (int i = 0; i < len; i++)
  {
    a[i] = data[i] != NULL_NODE ? newNode(data[i]) : NULL;
  }

  int preNull = 0;

  for (int i = 0; i < len; i++)
  {
    struct TreeNode *cur = a[i];
    if (cur)
    {
      int leftChilIndex = 2 * i + 1 - preNull * 2;
      if (leftChilIndex >= len)
      {
        break;
      }
      cur->left = a[leftChilIndex];
      int rightChildIndex = 2 * i + 2 - preNull * 2;
      if (rightChildIndex >= len)
      {
        break;
      }
      cur->right = a[rightChildIndex];
    }
    else
    {
      preNull++;
    }
  }
  res = a[0];

  return res;
}
