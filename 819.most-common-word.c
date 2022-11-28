/*
 * @lc app=leetcode id=819 lang=c
 *
 * [819] Most Common Word
 */

// @lc code=start
struct node_t
{
  char *w;
  int count;
  struct node_t *next;
};

#define SIZE      256

bool sameWord(char *a, char *b)
{
  return strcasecmp(a, b) == 0;
}

unsigned int hash(char *w, int capacity)
{
  unsigned int hash = 5381;

  for (int i = 0; w[i]; i++)
  {
    hash = ((hash << 5) + hash) + tolower(w[i]);
  }
  
  return hash % capacity;
}

struct node_t *create(char *w)
{
  struct node_t *new = calloc(1, sizeof(struct node_t));

  for (int i = 0; w[i]; i++)
  {
    w[i] = tolower(w[i]);
  }

  new->w = w;
  new->count = 1;

  return new;
}

struct node_t *add(struct node_t *table[], int capacity, char* w)
{
  if(capacity <= 0) return NULL;
  
  int idx = hash(w, capacity);

  if (!table[idx])
  {
    return table[idx] = create(w);
  }

  struct node_t *cur = table[idx];

  while (cur)
  {
    if (sameWord(w, cur->w))
    {
      cur->count++;
      break;
    }
    else if (!cur->next)
    {
      cur->next = create(w);
      cur = cur->next;
      break;
    }

    cur = cur->next;
  }

  return cur;
}

bool isExisting(struct node_t *table[], int capacity, char* w)
{
  if(capacity <= 0) return false;

  struct node_t *cur = table[hash(w, capacity)];
  bool existing = false;

  while (cur && !existing)
  {
    existing = sameWord(cur->w, w);
    cur = cur->next;
  }

  return existing;
}

char *mostCommonWord(char *paragraph, char **banned, int bannedSize)
{
  int max = 0;
  char *ret = NULL;
  const char delimiters[] = "!?',;. ";
  struct node_t *bannedList[bannedSize ? bannedSize : 1];
  struct node_t *wordList[SIZE] = {0};

  memset(bannedList, 0, sizeof(bannedList));

  for (int i = 0; i < bannedSize; i++)
  {
    add(bannedList, bannedSize, banned[i]);
  }

  char *w = strtok(paragraph, delimiters);

  while (w)
  {
    if (!isExisting(bannedList, bannedSize, w))
    {
      struct node_t *node = add(wordList, SIZE, w);

      if (node && (node->count > max))
      {
        max = node->count;
        ret = node->w;
      }
    }

    w = strtok(NULL, delimiters);
  }

  return ret;
}

// @lc code=end

