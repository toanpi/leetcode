/*
 * @lc app=leetcode id=953 lang=c
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
bool isAlienSorted(char **words, int wordsSize, char *order)
{
  int orders[26] = {0};

  for (int i = 0; order[i]; i++)
  {
    orders[order[i] - 'a'] = i;
  }

  for (int i = 1; i < wordsSize; i++)
  {
    char *pre = words[i - 1];
    char *cur = words[i];

    while (*pre || *cur)
    {
      if (*cur != *pre)
      {
        if (!(*cur) || ((*pre) && orders[*cur - 'a'] < orders[*pre - 'a']))
        {
          return false;
        }
        break;
      }

      if (*pre) pre++;
      if (*cur) cur++;
    }
  }

  return true;
}

// @lc code=end

