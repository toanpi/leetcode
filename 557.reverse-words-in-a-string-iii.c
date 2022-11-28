/*
 * @lc app=leetcode id=557 lang=c
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
char *reverseWords(char *s)
{
  char *w = s;

  while (*w)
  {
    int len = 0;

    while (w[len] && w[len] != ' ')
    {
      len++;
    }

    for (int i = 0; i < len / 2; i++)
    {
      char temp = w[i];
      w[i] = w[len - 1 - i];
      w[len - 1 - i] = temp;
    }

    if (*(w + len) != ' ')
    {
      break;
    }

    w += len + 1;
  }

  return s;
}

// @lc code=end

