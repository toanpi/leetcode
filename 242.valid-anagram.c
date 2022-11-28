/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

// @lc code=start

bool isAnagram(char *s, char *t)
{
  if (strlen(s) != strlen(t))
  {
    return false;
  }

  int table[26] = {0};
  bool ret = true;

  while (*s)
  {
    table[(*s) - 'a']++;
    table[(*t) - 'a']--;
    s++;
    t++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (table[i] != 0)
    {
      ret = false;
      break;
    }
  }

  return ret;
}

// @lc code=end

