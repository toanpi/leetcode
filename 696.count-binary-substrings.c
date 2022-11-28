/*
 * @lc app=leetcode id=696 lang=c
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
int countBinarySubstrings(char *s)
{
  int len = 1;
  int sum = 0;
  int preLen = 0;

  for (int i = 1; s[i - 1]; i++)
  {
    if (s[i] != s[i - 1])
    {
      sum += preLen < len ? preLen : len;
      preLen = len;
      len = 1;
    }
    else
    {
      len++;
    }
  }

  return sum;
}
// @lc code=end

