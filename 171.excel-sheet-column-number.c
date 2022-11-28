/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
int titleToNumber(char *columnTitle)
{
  int n = 0;

  for (int i = 0; columnTitle[i]; i++)
  {
    n *= 26;
    n += columnTitle[i] - 'A' + 1;
  }

  return n;
}

// @lc code=end

