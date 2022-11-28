/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

// @lc code=start

typedef struct
{
  int val;
  int id;
  struct node_t *next;
} node_t;

node_t table[256];

void add(int id)
{
  int pos = abs(id % 256);
  node_t *node = &table[pos];
  
  while (node)
  {
    // Found node
    if(node->id == id)
    {
      node->val++;
      break;
    }

    // Create new one
    if (!node->next)
    {
      node_t *new = calloc(1, sizeof(node_t));
      new->next = NULL;
      new->id = id;
      new->val = 1;
      node->next = new;
      break;
    }

    node = node->next;
  }
}

node_t *get(int id)
{
  int pos = abs(id % 256);
  node_t *node = &table[pos];

  while (node)
  {
    // Found node
    if (node->id == id)
    {
      break;
    }
    node = node->next;
  }

  return node;
}

int singleNumber(int *nums, int numsSize)
{
  int res = 0;
  int len = 0;

  memset(table, 0, sizeof(table));

  for (int i = 0; i < numsSize; i++)
  {
    add(nums[i]);
  }

  for (int i = 0; i < numsSize; i++)
  {
    node_t *node = get(nums[i]);

    if (node && node->val == 1)
    {
      res = nums[i];
      break;
    }
  }

  return res;
}

// @lc code=end

