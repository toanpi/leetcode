/*
 * @lc app=leetcode id=748 lang=c
 *
 * [748] Shortest Completing Word
 */

// @lc code=start

int encode(char *s, int *count)
{
  int len = 0;
  for (int i = 0; s[i]; i++)
  {
    if (isalpha(s[i]))
    {
      count[tolower(s[i]) - 'a']++;
    }
    len++;
  }
  return len;
}

char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{
  int code[26] = {0};
  int min = 16;
  char *ret = NULL;

  encode(licensePlate, code);

  for (int i = 0; i < wordsSize; i++)
  {
    int cnt[26] = {0};
    bool found = true;
    int len = encode(words[i], cnt);

    for (int j = 0; j < 26; j++)
    {
      if (code[j] && code[j] > cnt[j])
      {
        found = false;
        break;
      }
    }

    if (found && len < min)
    {
      ret = words[i];
      min = len;
    }
  }

  return ret;
}

// @lc code=end

