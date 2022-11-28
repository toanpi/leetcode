/*
 * @lc app=leetcode id=219 lang=c
 *
 * [219] Contains Duplicate II
 */

// @lc code=start


#define SIZE 1024

struct node_t
{
  int val;
  int index;
  struct node_t *next;
};

struct node_t *table[SIZE] = {0};

int hash(int val)
{
  return abs(val) % SIZE;
}

struct node_t * get(int val)
{
  struct node_t *node = table[hash(val)];

  while (node)
  {
    if (node->val == val)
    {
      break;
    }
    node = node->next;
  }

  return node;
}

void add(int val, int index)
{
  struct node_t *node = malloc(sizeof(struct node_t));
  node->next = NULL;
  node->val = val;
  node->index = index;

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

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
  memset(table, 0, sizeof(table));

  bool found = false;

  for (int i = 0; i < numsSize; i++)
  {
    struct node_t *node = get(nums[i]);

    if (node)
    {
      if (i - node->index <= k)
      {
        found = true;
        break;
      }
      else
      {
        node->index = i;
      }
    }
    else
    {
      add(nums[i], i);
    }
  }

  return found;
}

// @lc code=end

