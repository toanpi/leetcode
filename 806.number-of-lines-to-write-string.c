/*
 * @lc app=leetcode id=806 lang=c
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *numberOfLines(int *widths, int widthsSize, char *s, int *returnSize)
{
  int *ret = malloc(2 * sizeof(int));

  ret[0] = 1;
  ret[1] = 0;

  for (int i = 0; s[i]; i++)
  {
    ret[1] += widths[s[i] - 'a'];

    if (ret[1] > 100)
    {
      ret[1] = widths[s[i] - 'a'];
      ret[0]++;
    }
  }

  if (returnSize)
  {
    *returnSize = 2;
  }

  return ret;
}

// @lc code=end

