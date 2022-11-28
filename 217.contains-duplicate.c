/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */

// @lc code=start

#define SIZE 1024

struct node_t
{
  int val;
  struct node_t *next;
};

struct node_t *table[SIZE] = {0};

int hash(int val)
{
  return abs(val) % SIZE;
}

bool existing(int val)
{
  struct node_t *node = table[hash(val)];
  bool found = false;

  while (node)
  {
    if (node->val == val)
    {
      found = true;
      break;
    }
    node = node->next;
  }

  return found;
}

void add(int val)
{
  struct node_t *node = malloc(sizeof(struct node_t));
  node->next = NULL;
  node->val = val;

  if (!table[hash(val)])
  {
    table[hash(val)] = node;
    return;
  }

  struct node_t *cur = table[hash(val)];

  while (cur)
  {
    if (!cur->next)
    {
      cur->next = node;
      break;
    }

    cur = cur->next;
  }
}

bool containsDuplicate(int *nums, int numsSize)
{
  memset(table, 0, sizeof(table));

  bool duplicated = false;

  for (int i = 0; i < numsSize; i++)
  {
    if (existing(nums[i]))
    {
      duplicated = true;
      break;
    }
    else
    {
      add(nums[i]);
    }
  }

  return duplicated;
}

// @lc code=end
