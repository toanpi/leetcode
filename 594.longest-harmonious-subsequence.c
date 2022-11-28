/*
 * @lc app=leetcode id=594 lang=c
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start


#define SIZE 2048

struct node_t
{
  int val;
  int cnt;
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

struct node_t * add(int val)
{
  struct node_t *node = malloc(sizeof(struct node_t));
  node->next = NULL;
  node->val = val;
  node->cnt = 1;

  if (!table[hash(val)])
  {
    table[hash(val)] = node;
    return node;
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

  return node;
}

#define max(a, b) ((a) > (b) ? (a) : (b))

int findLHS(int *nums, int numsSize)
{
  int longest = 0;

  memset(table, 0, sizeof(table));

  for (int i = 0; i < numsSize; i++)
  {
    struct node_t *node = get(nums[i]);
    if (node)
    {
      node->cnt++;
    }
    else
    {
      node = add(nums[i]);
    }

    struct node_t *next = get(nums[i] + 1);
    struct node_t *pre = get(nums[i] - 1);

    if (next)
    {
      longest = max(longest, node->cnt + next->cnt);
    }

    if (pre)
    {
      longest = max(longest, node->cnt + pre->cnt);
    }
  }

  return longest;
}

// @lc code=end

