/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
int firstUniqChar(char *s)
{
  short table[26] = {0};

  for (int i = 0; s[i]; i++)
  {
    table[s[i] - 'a']++;
  }

  for (int i = 0; s[i]; i++)
  {
    if (table[s[i] - 'a'] == 1)
    {
      return i;
    }
  }

  return -1;
}

// @lc code=end

