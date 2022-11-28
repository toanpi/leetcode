/*
 * @lc app=leetcode id=389 lang=c
 *
 * [389] Find the Difference
 */

// @lc code=start

char findTheDifference(char *s, char *t)
{
  char c = 0;

  while (*s) c ^= *s++;

  while (*t) c ^= *t++;

  return c;
}

// @lc code=end

