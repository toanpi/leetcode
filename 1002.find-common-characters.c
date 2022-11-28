/*
 * @lc app=leetcode id=1002 lang=c
 *
 * [1002] Find Common Characters
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **commonChars(char **words, int wordsSize, int *returnSize)
{
  unsigned int result[26] = {0};
  unsigned int cnt[26] = {0};
  int size = 0;

  memset(result, 0xFF, sizeof(result));

  for (int i = 0; i < wordsSize; i++)
  {
    char *s = words[i];
    int num = 0;

    memset(cnt, 0, sizeof(cnt));

    while (*s)
    {
      cnt[(*s) - 'a']++;
      s++;
    }

    for (int j = 0; j < 26; j++)
    {
      if (cnt[j] < result[j])
      {
        result[j] = cnt[j];
      }
    }
  }

  char **ret = calloc(100, sizeof(char *));
  size = 0;

  for (int i = 0; i < 26; i++)
  {
    for (int k = 0; k < result[i]; k++)
    {
      ret[size] = calloc(2, sizeof(char));
      sprintf(ret[size], "%c", i + 'a');
      size++;
    }
  }

  *returnSize = size;

  return ret;
}

// @lc code=end

