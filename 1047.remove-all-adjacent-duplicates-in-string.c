/*
 * @lc app=leetcode id=1047 lang=c
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start

char *removeDuplicates(char *s)
{
  int l = 0;
  int i = 0;

  while (s[i])
  {
    if ((l <= 0) || (s[i] != s[l - 1]))
    {
      s[l++] = s[i];
    }
    else
    {
      l--;
    }

    i++;
  }

  s[l] = '\0';

  return s;
}

// @lc code=end

