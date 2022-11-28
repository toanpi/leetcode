/*
 * @lc app=leetcode id=821 lang=c
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define min(a, b)  ((a) < (b) ? (a) : (b))

int *shortestToChar(char *s, char c, int *returnSize)
{
  int len = strlen(s);
  int *ret = calloc(len, sizeof(int));
  int idx = 0;
  int last = -1;
  int i = 0;
  int j = 0;

  while (i < len)
  {
    while ((i < len) && (s[i] != c))
    {
      i++;
    }

    j = last + 1;

    while (j <= i && j < len)
    {
      if (last < 0)
      {
        ret[idx++] = i - j;
      }
      else if (i >= len)
      {
        ret[idx++] = j - last;
      }
      else
      {
        ret[idx++] = min(j - last, i - j);
      }

      j++;
    }

    last = i;
    i++;
  }

  *returnSize = len;
  return ret;
}
// @lc code=end
