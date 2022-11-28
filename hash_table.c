
#define SIZE 1024

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
