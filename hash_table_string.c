
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
