/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

// @lc code=start

#define isOpen(c)  ((c) == '(' || (c) == '[' || (c) == '{')
#define pair(c, o) ((c + o) == '(' + ')' || (c + o) == '[' + ']' || (c + o) == '{' + '}')

bool isValid(char *s)
{
  int openCnt = 0;

  for (int i = 0; s[i]; i++)
  {
    if (isOpen(s[i]))
    {
      s[openCnt++] = s[i];
      continue;
    }

    if ((openCnt <= 0) || !pair(s[i], s[openCnt - 1]))
    {
      return false;
    }

    openCnt--;
  }

  return openCnt == 0;
}

// @lc code=end

