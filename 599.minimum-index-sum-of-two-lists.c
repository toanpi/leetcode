/*
 * @lc app=leetcode id=599 lang=c
 *
 * [599] Minimum Index Sum of Two Lists
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define SIZE 1024

struct node_t
{
  char *s;
  int idx;
  struct node_t *next;
};

struct node_t *table[SIZE] = {0};

int hash(char *s)
{
  int hash = 0;

  for (int i = 0; s[i]; i++)
  {
    hash += s[i];
  }

  return hash % SIZE;
}

struct node_t * get(char *s)
{
  struct node_t *node = table[hash(s)];

  while (node)
  {
    if (!strcmp(node->s, s))
    {
      break;
    }
    node = node->next;
  }

  return node;
}

struct node_t * add(char *s, int idx)
{
  struct node_t *node = malloc(sizeof(struct node_t));
  node->next = NULL;
  node->s = s;
  node->idx = idx;

  if (!table[hash(s)])
  {
    table[hash(s)] = node;
    return node;
  }

  struct node_t *cur = table[hash(s)];

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

char **findRestaurant(char **list1, int list1Size,
                      char **list2, int list2Size,
                      int *returnSize)
{
  int **ret = malloc((list1Size > list2Size ? list2Size : list1Size) * sizeof(char *));
  int min = list1Size + list2Size;
  int len = 0;
  
  memset(table, 0, sizeof(table));

  for (int i = 0; i < list1Size; i++)
  {
    add(list1[i], i);
  }

  for (int i = 0; i < list2Size; i++)
  {
    struct node_t *node = get(list2[i]);

    if (node)
    {
      if (i + node->idx < min)
      {
        len = 0;
        ret[len++] = list2[i];
        min = i + node->idx;
      }
      else if (i + node->idx == min)
      {
        ret[len++] = list2[i];
      }
    }
  }

  if (returnSize)
  {
    *returnSize = len;
  }

  return ret;
}

// @lc code=end
