/*
 * @lc app=leetcode id=1021 lang=c
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
char *removeOuterParentheses(char *s)
{
  char *ps = s;
  char *start = s;
  int count = 0;
  bool atBegin = true;

  while (*ps)
  {
    count += ((*ps) == '(') ? 1 : -1;

    if (count >= 1 && !atBegin)
    {
      *start++ = *ps;
    }

    atBegin = (count == 0);
    ps++;
  }

  *start = '\0';

  return s;
}

// @lc code=end

